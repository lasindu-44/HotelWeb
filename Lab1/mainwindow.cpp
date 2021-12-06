#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->listWidget->selectionModel(),
    SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this,
    SLOT(updateDeleteEnabled()));

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    QString newText = QInputDialog::getText(this, "Enter text", "Text:");
    if( !newText.isEmpty() )
     ui->listWidget->addItem(newText);

}


void MainWindow::on_deleteButton_clicked()
{

    foreach (QListWidgetItem *item, ui->listWidget->selectedItems())
    delete item;

}

void MainWindow::updateDeleteEnabled()
{
ui->deleteButton->setEnabled(ui->listWidget->selectedItems().count()!=0);
}





void MainWindow::on_clearButton_clicked()
{

}

