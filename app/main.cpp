#include "ndn_app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ndn_app w;
    w.show();

    return a.exec();
}
