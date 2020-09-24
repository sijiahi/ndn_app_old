#include "mainwindow.h"
#include <QApplication>
//#include "dialog.h"
//Include and trigger by button
#include "nfd_checker.h"
int main(int argc, char *argv[])
{
    QApplication ndn_app(argc, argv);
    MainWindow w;
     w.show();
    //Include and trigger by button
    //nfd_checker checker;
    //checker.run();
     //Nfd_Manegement nfd_manager;
     // nfd_manager.show();

    return ndn_app.exec();
}
