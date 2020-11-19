#include "messager.h"
#include "ui_messager.h"

Messager::Messager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messager)
{
    ui->setupUi(this);
}

Messager::~Messager()
{
    delete ui;
}
