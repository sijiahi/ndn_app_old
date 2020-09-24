#include "nfd_manegement.h"
#include "ui_nfd_manegement.h"

Nfd_Manegement::Nfd_Manegement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nfd_Manegement)
{
    ui->setupUi(this);
}



Nfd_Manegement::~Nfd_Manegement()
{
    delete ui;
}

void Nfd_Manegement::on_pushButton_clicked()
{
}
