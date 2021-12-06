#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/images/Images/id1.jpeg");
    int w=ui->lblpic->width();
    int h=ui->lblpic->height();
    ui->lblpic->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    ui->statusbar->addPermanentWidget(ui->progressBar);
    ui->statusbar->addPermanentWidget(ui->label_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    QString Username=ui->username->text();
    QString Password=ui->password->text();

    if(Username=="text" && Password=="text"){
        //QMessageBox::information(this,"Login","Username and Password Correct");
        //hide();
        //obj=new secDialog(this);
        //obj->show();
        ui->statusbar->showMessage("Username and Password Correct",5000);


    }else{
        QMessageBox:: StandardButton reply=QMessageBox::warning(this,"Loging","Username and Password InCorrect Try again",QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::No){
            QApplication::quit();
        }else{
           ui->username->setText(NULL);
           ui->password->setText(NULL);
        }
    }
}

