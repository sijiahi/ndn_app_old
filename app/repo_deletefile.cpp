#include "repo_putfile.h"
#include <QInputDialog>
#include <QFileDialog>
namespace repo{
void
repo_putfile::prepareNextData(uint64_t referenceSegmentNo)
{
  // make sure m_data has [referenceSegmentNo, referenceSegmentNo + PRE_SIGN_DATA_COUNT] Data
  if (m_isFinished)
    return;
  size_t nDataToPrepare = PRE_SIGN_DATA_COUNT;
  if (!m_data.empty()) {
    uint64_t maxSegmentNo = m_data.rbegin()->first;
    if (maxSegmentNo - referenceSegmentNo >= nDataToPrepare) {
      // nothing to prepare
      return;
    }
    nDataToPrepare -= maxSegmentNo - referenceSegmentNo;
  }

  for (size_t i = 0; i < nDataToPrepare && !m_isFinished; ++i) {
    uint8_t buffer[DEFAULT_BLOCK_SIZE];
    auto readSize = boost::iostreams::read(*insertStream,
                                           reinterpret_cast<char*>(buffer), DEFAULT_BLOCK_SIZE);
    if (readSize <= 0) {
      BOOST_THROW_EXCEPTION(Error("Error reading from the input stream"));
    }

    auto data = make_shared<ndn::Data>(Name(m_dataPrefix).appendSegment(m_currentSegmentNo));

    if (insertStream->peek() == std::istream::traits_type::eof()) {
      data->setFinalBlock(ndn::name::Component::fromSegment(m_currentSegmentNo));
      m_isFinished = true;
    }
    data->setContent(buffer, readSize);
    data->setFreshnessPeriod(freshnessPeriod);
    signData(*data);
    m_data.insert(std::make_pair(m_currentSegmentNo, data));
    ++m_currentSegmentNo;
  }
}
void
repo_putfile::setInsertStream(std::istream* inputFileStream){
    insertStream = inputFileStream;
    setSingle();
}
void
repo_putfile::setSingle(){
 if (insertStream->peek() != std::istream::traits_type::eof()) {
     isSingle = false;
 }
 else{
     isSingle = true;
 }
}
void
repo_putfile::run()
{
  m_dataPrefix = ndnName;
  if (!isUnversioned)
    m_dataPrefix.appendVersion(m_timestampVersion);
  if (isVerbose)
    std::cerr << "setInterestFilter for " << m_dataPrefix << std::endl;
  m_face.setInterestFilter(m_dataPrefix,
                           bind(&repo_putfile::onInterestSelect, this, _1, _2),
                           bind(&repo_putfile::onRegisterSuccess, this, _1),
                           bind(&repo_putfile::onRegisterFailed, this, _1, _2));

  if (hasTimeout)
    m_scheduler.schedule(timeout, [this] { stopProcess(); });

  m_face.processEvents();
}

void
repo_putfile::onRegisterSuccess(const Name& prefix)
{
  std::cout<<"Register prefix: "<<prefix<<" Success! "<<std::endl;
  startInsertCommand();
}

void
repo_putfile::startInsertCommand()
{
  //** Insert Command must set 3 arguments:
  //1 PrefixName(setName(String))
  //2 StartBlockId;
  //2 EndblockId;
  RepoCommandParameter parameters;
  parameters.setName(m_dataPrefix);
//****Need to set Start Block ID and End Block Id to enable Data Transmission!!!!
  if (!isSingle) {
    parameters.setStartBlockId(0);
  }
  ndn::Interest commandInterest = generateCommandInterest(repoPrefix, "insert", parameters);
  std::cout<<"Inserting Command"<<commandInterest<<std::endl;
  m_face.expressInterest(commandInterest,
                         bind(&repo_putfile::onInsertCommandResponse, this, _1, _2),
                         bind(&repo_putfile::onInsertCommandNack, this, _1), // Nack
                         bind(&repo_putfile::onInsertCommandTimeout, this, _1));
}

void
repo_putfile::onInsertCommandResponse(const ndn::Interest& interest, const ndn::Data& data)
{
  std::cout<<"Got Insert Comment response Content"<<data<<std::endl;
  RepoCommandResponse response(data.getContent().blockFromValue());
  //std::cout<<"ResponseInitialized"<<response<<std::endl;
  auto statusCode = response.getCode();
  std::cout<<"Received Responsewith code : "+statusCode<<std::endl;
  if (statusCode >= 400) {
    BOOST_THROW_EXCEPTION(Error("insert command failed with code " +
                                boost::lexical_cast<std::string>(statusCode)));
  }
  std::cout<<"Setting processId: "<<response.getProcessId();
  m_processId = response.getProcessId();

  m_scheduler.schedule(m_checkPeriod, [this] { startCheckCommand(); });
}

void
repo_putfile::onInsertCommandNack(const ndn::Interest& interest)
{
    BOOST_THROW_EXCEPTION(Error("insertion command nacked"));

}

void
repo_putfile::onInsertCommandTimeout(const ndn::Interest& interest)
{
  BOOST_THROW_EXCEPTION(Error("command response timeout"));
}

void
repo_putfile::onInterestSelect(const ndn::Name& prefix, const ndn::Interest& interest)
{
    uint8_t buffer[DEFAULT_BLOCK_SIZE];
    std::streamsize readSize =
        boost::iostreams::read(*insertStream, reinterpret_cast<char*>(buffer), DEFAULT_BLOCK_SIZE);
  if (insertStream->peek() != std::istream::traits_type::eof()) {
      std::cout<<"Processing segmented command"<<std::endl;
      if (interest.getName().size() != prefix.size() + 1) {
        if (isVerbose) {
          std::cerr << "Error processing incoming interest " << interest << ": "
                    << "Unrecognized Interest" << std::endl;
        }
        return;
      }
      uint64_t segmentNo;
      try {
        ndn::Name::Component segmentComponent = interest.getName().get(prefix.size());
        segmentNo = segmentComponent.toSegment();
      }
      catch (const tlv::Error& e) {
        if (isVerbose) {
          std::cerr << "Error processing incoming interest " << interest << ": "
                    << e.what() << std::endl;
        }
        return;
      }
      prepareNextData(segmentNo);
      DataContainer::iterator item = m_data.find(segmentNo);
      if (item == m_data.end()) {
        if (isVerbose) {
          std::cerr << "Requested segment [" << segmentNo << "] does not exist" << std::endl;
        }
        return;
      }
      if (m_isFinished) {
        uint64_t final = m_currentSegmentNo - 1;
        item->second->setFinalBlock(ndn::name::Component::fromSegment(final));
      }
      std::cout<<"Transmitting data: "<<*item->second<<std::endl;
      m_face.put(*item->second);
    return;
  }
  else{
      std::cout<<"Processing single insert interest"<<std::endl;
      std::cerr << "Received unexpected interest " << interest.getName() <<"\nExpecting Prefix: "<<prefix<<std::endl;
      BOOST_ASSERT(prefix == m_dataPrefix);
      /*if (prefix != interest.getName()) {
        if (isVerbose) {
          std::cerr << "Received unexpected interest " << interest.getName() <<"\nExpecting Prefix: "<<prefix<<std::endl;
        }
        return;
      }*/

      auto data = make_shared<ndn::Data>(m_dataPrefix);
      data->setContent(buffer, readSize);
      data->setFreshnessPeriod(freshnessPeriod);
      signData(*data);
      m_face.put(*data);
      m_isFinished = true;
    return;
  }
}
void
repo_putfile::onInterest(const ndn::Name& prefix, const ndn::Interest& interest)
{
  std::cout<<"Received Interest"<<interest<<std::endl;
  if (interest.getName().size() != prefix.size() + 1) {
    if (isVerbose) {
      std::cerr << "Error processing incoming interest " << interest << ": "
                << "Unrecognized Interest" << std::endl;
    }
    return;
  }

  uint64_t segmentNo;
  try {
    ndn::Name::Component segmentComponent = interest.getName().get(prefix.size());
    segmentNo = segmentComponent.toSegment();
  }
  catch (const tlv::Error& e) {
    if (isVerbose) {
      std::cerr << "Error processing incoming interest " << interest << ": "
                << e.what() << std::endl;
    }
    return;
  }

  prepareNextData(segmentNo);

  DataContainer::iterator item = m_data.find(segmentNo);
  if (item == m_data.end()) {
    if (isVerbose) {
      std::cerr << "Requested segment [" << segmentNo << "] does not exist" << std::endl;
    }
    return;
  }

  if (m_isFinished) {
    uint64_t final = m_currentSegmentNo - 1;
    item->second->setFinalBlock(ndn::name::Component::fromSegment(final));
  }
  std::cout<<"Transmitting data: "<<*item->second<<std::endl;
  m_face.put(*item->second);
}

void
repo_putfile::onSingleInterest(const ndn::Name& prefix, const ndn::Interest& interest)
{
  BOOST_ASSERT(prefix == m_dataPrefix);

  if (prefix != interest.getName()) {
    if (isVerbose) {
      std::cerr << "Received unexpected interest " << interest << std::endl;
    }
    return;
  }

  uint8_t buffer[DEFAULT_BLOCK_SIZE];
  std::streamsize readSize =
    boost::iostreams::read(*insertStream, reinterpret_cast<char*>(buffer), DEFAULT_BLOCK_SIZE);

  if (readSize <= 0) {
    BOOST_THROW_EXCEPTION(Error("Error reading from the input stream"));
  }

  if (insertStream->peek() != std::istream::traits_type::eof()) {
    BOOST_THROW_EXCEPTION(Error("Input data does not fit into one Data packet"));
  }

  auto data = make_shared<ndn::Data>(m_dataPrefix);
  data->setContent(buffer, readSize);
  data->setFreshnessPeriod(freshnessPeriod);
  signData(*data);
  m_face.put(*data);

  m_isFinished = true;
}

void
repo_putfile::onRegisterFailed(const ndn::Name& prefix, const std::string& reason)
{
  BOOST_THROW_EXCEPTION(Error("onRegisterFailed: " + reason));
}

void
repo_putfile::stopProcess()
{
  m_face.getIoService().stop();
}

void
repo_putfile::signData(ndn::Data& data)
{
  if (useDigestSha256) {
    m_keyChain.sign(data, ndn::signingWithSha256());
  }
  else if (identityForData.empty())
    m_keyChain.sign(data);
  else {
    m_keyChain.sign(data, ndn::signingByIdentity(identityForData));
  }
}

void
repo_putfile::startCheckCommand()
{
  //TODO: Set Command Parameters
  RepoCommandParameter parameters;
  parameters.setName(m_dataPrefix);
  parameters.setProcessId(m_processId);
  ndn::Interest checkInterest = generateCommandInterest(repoPrefix, "insertcheck",
                                                        parameters);
  std::cout<<"Expressing Check Command Interest"<<checkInterest<<std::endl;
  m_face.expressInterest(checkInterest,
                         bind(&repo_putfile::onCheckCommandResponse, this, _1, _2),
                         bind(&repo_putfile::onCheckCommandNack, this, _1), // Nack
                         bind(&repo_putfile::onCheckCommandTimeout, this, _1));
}

void
repo_putfile::onCheckCommandResponse(const ndn::Interest& interest, const ndn::Data& data)
{
  ndn::mgmt::ControlResponse Controlresponse(data.getContent().blockFromValue());
  RepoCommandResponse response(data.getContent().blockFromValue());
  auto statusCode = response.getCode();
  if (statusCode >= 400) {
    BOOST_THROW_EXCEPTION(Error("Insert check command failed with code: " +
                                boost::lexical_cast<std::string>(statusCode)));
  }

  if (m_isFinished) {
    uint64_t insertCount = response.getInsertNum();
    std::cout<<"Insert Num"<<insertCount<<std::endl;
    if (isSingle) {
      if (insertCount == 1) {
        m_face.getIoService().stop();
        return;
      }
    }
    // Technically, the check should not infer, but directly has signal from repo that
    // write operation has been finished

    if (insertCount == m_currentSegmentNo) {
      m_face.getIoService().stop();
      return;
    }
  }

  m_scheduler.schedule(m_checkPeriod, [this] { startCheckCommand(); });
}

void
repo_putfile::onCheckCommandNack(const ndn::Interest& interest)
{
  BOOST_THROW_EXCEPTION(Error("check response Nacked"));
}

void
repo_putfile::onCheckCommandTimeout(const ndn::Interest& interest)
{
  BOOST_THROW_EXCEPTION(Error("check response timeout"));
}

ndn::Interest
repo_putfile::generateCommandInterest(const ndn::Name& commandPrefix, const std::string& command,
                                    const RepoCommandParameter& commandParameter)
{
  Name cmd = commandPrefix;
  cmd
    .append(command)
    .append(commandParameter.wireEncode());
  ndn::Interest interest;

  if (identityForCommand.empty())
    interest = m_cmdSigner.makeCommandInterest(cmd);
  else {
    interest = m_cmdSigner.makeCommandInterest(cmd, ndn::signingByIdentity(identityForCommand));
  }

  interest.setInterestLifetime(interestLifetime);
  return interest;
}


} // namespace repo


