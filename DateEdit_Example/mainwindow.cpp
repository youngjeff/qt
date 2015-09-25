#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDate>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->showPushButton,SIGNAL(clicked()),this,SLOT(showTime()));
    connect(ui->quitPushButton,SIGNAL(clicked()),this,SLOT(quitTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showTime()
{
    QDate timeString;
    timeString=ui->dateEdit->date();
    QString outPutString;
    outPutString=timeString.toString();
    QMessageBox::information(this,tr("show"),outPutString);
}
void MainWindow::quitTime()
{
    close();
}
