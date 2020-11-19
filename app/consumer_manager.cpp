#include "consumer_manager.h"
#include "ui_consumer_manager.h"

Consumer_manager::Consumer_manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Consumer_manager)
{
    ui->setupUi(this);
}

Consumer_manager::~Consumer_manager()
{
    delete ui;
}
