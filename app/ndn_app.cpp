#include "ndn_app.h"
#include "ui_ndn_app.h"
#include "nfd_checker.h"
#include "dialog.h"
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

void ndn_app::on_pushButton_clicked()
{
    Dialog d;
    d.show();
    nfd_checker checker;
    checker.run();

}
