#ifndef REPO_PUTFILE_H
#define REPO_PUTFILE_H




/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014-2019, Regents of the University of California.
 *
 * This file is part of NDN repo-ng (Next generation of NDN repository).
 * See AUTHORS.md for complete list of repo-ng authors and contributors.
 *
 * repo-ng is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * repo-ng is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * repo-ng, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "repo-ng/repo-command-parameter.hpp"
#include "repo-ng/repo-command-response.hpp"

#include <QObject>
#include <QInputDialog>
#include <QFileDialog>
#include <ndn-cxx/face.hpp>
#include <ndn-cxx/security/command-interest-signer.hpp>
#include <ndn-cxx/security/key-chain.hpp>
#include <ndn-cxx/security/signing-helpers.hpp>
#include <ndn-cxx/util/scheduler.hpp>

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/iostreams/operations.hpp>
#include <boost/iostreams/read.hpp>

namespace repo {

using namespace ndn::time;

using std::shared_ptr;
using std::make_shared;
using std::bind;

static const uint64_t DEFAULT_BLOCK_SIZE = 1000;
static const uint64_t DEFAULT_INTEREST_LIFETIME = 4000;
static const uint64_t DEFAULT_FRESHNESS_PERIOD = 10000;
static const uint64_t DEFAULT_CHECK_PERIOD = 1000;
static const size_t PRE_SIGN_DATA_COUNT = 11;
static int putfile();

class repo_putfile : public QObject
{
        Q_OBJECT
public:
  class Error : public std::runtime_error
  {
  public:
    using std::runtime_error::runtime_error;
  };

 explicit repo_putfile(QObject *parent = nullptr)
    : isUnversioned(true)
    , isSingle(false)
    , useDigestSha256(false)
    , freshnessPeriod(DEFAULT_FRESHNESS_PERIOD)
    , interestLifetime(DEFAULT_INTEREST_LIFETIME)
    , hasTimeout(false)
    , timeout(0)
    , insertStream(nullptr)
    , isVerbose(true)
    , m_scheduler(m_face.getIoService())
    , m_timestampVersion(toUnixTimestamp(system_clock::now()).count())
    , m_processId(0)
    , m_checkPeriod(DEFAULT_CHECK_PERIOD)
    , m_currentSegmentNo(0)
    , m_isFinished(false)
    , m_cmdSigner(m_keyChain)
  {
  }

  void
  run();
  ////////////////////////
  void
  setInsertStream(std::istream* inputFileStream);
  ///////////////////////////


private:
  //////////////////////
  void
  setSingle();
  ////////////////////////
  void
  prepareNextData(uint64_t referenceSegmentNo);

  void
  startInsertCommand();

  void
  onInsertCommandResponse(const ndn::Interest& interest, const ndn::Data& data);
  /////////////////////////////////////
  //void
  //setSingle(const )
  /// /////////////////////////////////
  //////////////////////
  void
  onInsertCommandNack(const ndn::Interest& interest);
///////////////////////////////
  void
  onInsertCommandTimeout(const ndn::Interest& interest);
  void
  onInterestSelect(const ndn::Name& prefix, const ndn::Interest& interest);
  void
  onInterest(const ndn::Name& prefix, const ndn::Interest& interest);

  void
  onSingleInterest(const ndn::Name& prefix, const ndn::Interest& interest);

  void
  onRegisterSuccess(const ndn::Name& prefix);

  void
  onRegisterFailed(const ndn::Name& prefix, const std::string& reason);

  void
  stopProcess();

  void
  signData(ndn::Data& data);

  void
  startCheckCommand();

  void
  onCheckCommandResponse(const ndn::Interest& interest, const ndn::Data& data);

void onCheckCommandNack(const ndn::Interest& interest);

  void
  onCheckCommandTimeout(const ndn::Interest& interest);

  ndn::Interest
  generateCommandInterest(const ndn::Name& commandPrefix, const std::string& command,
                          const RepoCommandParameter& commandParameter);


public:
  bool isUnversioned;
  bool isSingle;
  bool useDigestSha256;
  std::string identityForData;
  std::string identityForCommand;
  milliseconds freshnessPeriod;
  milliseconds interestLifetime;
  bool hasTimeout;
  milliseconds timeout;
  ndn::Name repoPrefix;
  ndn::Name ndnName;

  bool isVerbose;

private:
  ndn::Face m_face;
  ndn::Scheduler m_scheduler;
  ndn::KeyChain m_keyChain;
  uint64_t m_timestampVersion;
  uint64_t m_processId;
  milliseconds m_checkPeriod;
  size_t m_currentSegmentNo;
  bool m_isFinished;
  ndn::Name m_dataPrefix;
  std::istream* insertStream;

  using DataContainer = std::map<uint64_t, shared_ptr<ndn::Data>>;
  DataContainer m_data;
  ndn::security::CommandInterestSigner m_cmdSigner;
signals:

public slots:
    };
////////////////////////////////////
static int
putfile(){
repo_putfile repo_putfile;
repo_putfile.isUnversioned = true;
repo_putfile.isSingle = true;
repo_putfile.isVerbose = true;
bool nameset = false;
std::string repoPrefix;
std::string ndnName;
while(!nameset){
repoPrefix = QInputDialog::getText(NULL, "Input Dialog",
                                                   "Please repoPrefix",
                                                   QLineEdit::Normal,
                                                   "/example/repo/1",
                                                   &nameset).toStdString();
}

nameset = false;
while(!nameset){
ndnName = QInputDialog::getText(NULL, "Input Dialog",
                                                   "Please Enter ndnName",
                                                   QLineEdit::Normal,
                                                   "/sijiahi",
                                                   &nameset).toStdString();}

repo_putfile.repoPrefix = Name(repoPrefix);
repo_putfile.ndnName = Name(ndnName);
std::string file_name = QFileDialog::getOpenFileName(NULL,"标题",".","*.*").toStdString();
std::ifstream inputFileStream(file_name, std::ios::in | std::ios::binary);
if (!inputFileStream.is_open()) {
  std::cerr << "ERROR: cannot open " << file_name << std::endl;
  return 2;}
std::cout<<"Reading file"<<file_name<<std::endl;
repo_putfile.setInsertStream(&inputFileStream);
repo_putfile.run();
}
/////////////////////////////
} //repo

#endif // REPO_PUTFILE_H