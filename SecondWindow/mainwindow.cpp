#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seconddialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    SecondDialog obj;
    obj.setModal(true);
    obj.exec();
}

