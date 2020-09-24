#include "nfd_checker.h"
#include <QMessageBox>

nfd_checker::nfd_checker()
{
}
void
nfd_checker::run(){
    try{
        Name interestName("/localhost/nfd/status/general");
        Interest  interest(interestName);
        std::cout << "Sending Interest " << interest << std::endl;
        m_face.expressInterest(interest,
                               bind(&nfd_checker::onData, this,  _1, _2),
                               bind(&nfd_checker::onNack, this, _1, _2),
                               bind(&nfd_checker::onTimeout, this, _1));
        // processEvents will block until the requested data is received or a timeout occurs
        m_face.processEvents();}
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        QMessageBox msgBox;
        msgBox.setText(e.what() );
        msgBox.exec();
      }
}

void
nfd_checker::onData(const Interest& interest, const Data& data){
       std::cout << "Received Data " << data << std::endl;
}
void
nfd_checker::onNack(const Interest& interest, const Nack& nack){
    std::cout << "Received Nack with reason " << nack.getReason() << std::endl;
}
void
nfd_checker::onTimeout(const Interest& interest){
      std::cout << "Timeout for " << interest << std::endl;
}

