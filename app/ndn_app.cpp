#include "ndn_app.h"
#include "ui_ndn_app.h"
#include "nfd_checker.h"
//This is to check if the path exist
#include <dirent.h>


ndn_app::ndn_app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ndn_app)
{
    ui->setupUi(this);

}

ndn_app::~ndn_app()
{
    delete ui;
}



void ndn_app::on_nfd_Manager_clicked()
{
    try{
        std::string g_Path;
        if ((opendir(std::string("./nfd-status-http-server/").c_str())) != NULL)
         {
            g_Path = "./nfd-status-http-server/";
        }
        else if((opendir(std::string("../nfd-status-http-server/").c_str())) != NULL){
            g_Path = "../nfd-status-http-server/";
        }
        if (g_Path == "")
         {
             QMessageBox error;
             char *buffer = getcwd(NULL, 0);
             error.setText(QString::fromStdString(std::string("Can not find server app path from: ")+buffer));
             error.exec();
             return;
        }
        QProcess p;
        QStringList params;
        params << QString::fromStdString(g_Path+"nfd-status-http-server.py");
        p.execute("python3.exe", params);
    }
    catch(const std::exception& e){
            std::cout<<"ERROR :"<<e.what()<<std::endl;
            QMessageBox errorAlert;
            errorAlert.setText(e.what());
            errorAlert.show();
    }

//    QWebEngineView view;
//    view.load(QUrl("localhost:8080"));
//    view.show();
    nfd_checker checker;
    checker.check();
}

void ndn_app::on_consumer_app_clicked()
{
try{
    if (manager== NULL){
    manager = new Consumer_manager();
    }
    manager->show();}
    catch(const std::exception& e){
        std::cout<<"ERROR :"<<e.what()<<std::endl;
        QMessageBox errorAlert;
        errorAlert.setText(e.what());
        errorAlert.show();
    }
}

void ndn_app::on_to_DB_clicked()
{
    try {

       repo::putfile();
       //repo::putfile();
    }
    catch (const std::exception& e) {
      std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

void ndn_app::on_delete_DB_clicked()
{
    try {
       repo::deletefile();
       //repo::putfile();
    }
    catch (const std::exception& e) {
      std::cerr << "ERROR: " << e.what() << std::endl;
     }
}

void ndn_app::on_chat_app_clicked()
{
    try{
        std::string g_Path;
        if ((opendir(std::string("./chat_ndn-cpp/").c_str())) != NULL)
         {
            g_Path = "./chat_ndn-cpp/";
        }
        else if((opendir(std::string("../chat_ndn-cpp/").c_str())) != NULL){
            g_Path = "../chat_ndn-cpp/";
        }
        if (g_Path == "")
         {
             QMessageBox error;
             char *buffer = getcwd(NULL, 0);
             error.setText(QString::fromStdString(std::string("Can not find chat app path from: ")+buffer));
             error.exec();
             return;
        }
        chatList = new QProcess(this);
        QString strCmd;
        strCmd = QString::fromStdString(g_Path+std::string("app"));
        chatList->start("bash", QStringList() <<"-c" << strCmd);
    }
    catch(const std::exception& e){
            std::cout<<"ERROR :"<<e.what()<<std::endl;
            QMessageBox errorAlert;
            errorAlert.setText(e.what());
            errorAlert.show();
    }
}
