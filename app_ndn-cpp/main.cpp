#include "ndn_app.h"
#include <QApplication>
#include "test-chrono-chat.cpp"

int main(int argc, char *argv[])
{
    chatgo(argc,argv);
    QApplication a(argc, argv);
    ndn_app w;
    w.show();

    return a.exec();
}
