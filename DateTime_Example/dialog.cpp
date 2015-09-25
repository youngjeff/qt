#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->showPushButton,SIGNAL(clicked()),this,SLOT(showTime()));
    connect(ui->quitPushButton,SIGNAL(clicked()),this,SLOT(quitTime()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::showTime()
{
    QDate dateString;
    QTime timeString;
    dateString=ui->dateTimeEdit->date();
    timeString=ui->dateTimeEdit->time();
    QString outPutString;
    outPutString=dateString.toString()+'\n'+timeString.toString();
    QMessageBox::information(this,tr("show time"),outPutString);
}
void Dialog::quitTime()
{
    close();
}
