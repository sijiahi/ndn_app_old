#include "ndn_app.h"
#include "ui_ndn_app.h"

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
