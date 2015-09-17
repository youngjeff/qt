#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <iostream>
#include "sizewidget.h"
#include "widget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "timeme.h"
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

void MainWindow::on_pushButton_2_clicked()
{
    QString usrName, passWord;
    int temp=0;
    QString usrjudge = NULL,passjudge = NULL;
    usrName = ui->usrLineEdit->text();
    passWord = ui->passLineEdit->text();
   if(usrName ==NULL || passWord == NULL)
   {
    QMessageBox::information(this,"me","您还没有注册");

   }
   else{
    QFile inFile("./usrname");
    if(inFile.open(QIODevice::ReadWrite))
        {
        QTextStream textstream(&inFile);

        while(!textstream.atEnd()){
        textstream>>usrjudge>>passjudge;
        if(usrjudge == usrName && passjudge == passWord)
        {
           temp = 1;
           break;
        }
        }
        if(temp == 1)
        {
            //Widget *widGet;
            //widGet = new Widget();
            //widGet->show();
            //PrograssBar *PrograssBarMes ;
            //PrograssBarMes = new PrograssBar(this);
            //PrograssBarMes->show();
            TimeMe *timeMe = new TimeMe();
            timeMe->show();
            this->close();
        }

        else{
        QMessageBox::information(this,"me","您还没有注册");
    }}}
}

void MainWindow::on_sizeUpButton_clicked()
{
    SizeWidget *sizeMe  ;
    sizeMe = new SizeWidget();
    sizeMe->show();
    this->close();
}

void MainWindow::on_cancerButton_clicked()
{
    close();
}
