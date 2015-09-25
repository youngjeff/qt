#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->showPushButton,SIGNAL(clicked()),this,SLOT(getIdNumber()));
    connect(ui->clearPushButton,SIGNAL(clicked()),this,SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getIdNumber()
{
    QString outPutString;
    if(ui->p1radioButton->isChecked()==true)
    {
        outPutString+="you choose one\n";
    }
    if(ui->p2radioButton->isChecked()==true)
    {
        outPutString+="you choose two\n";
    }
    if(ui->p3radioButton->isChecked()==true)
    {
        outPutString+="you choose three\n";
    }
    if(ui->p4radioButton->isChecked()==true)
    {
        outPutString+="you choose four\n";
    }
    QMessageBox::information(this,tr("show you"),outPutString);
}
void MainWindow::clear()
{
    ui->p1radioButton->setChecked(true);
    ui->p2radioButton->setChecked(true);
    ui->p3radioButton->setChecked(true);
    ui->p4radioButton->setChecked(true);
}
