#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nfd_checker.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    nfd_checker checker;
    checker.run();
}
