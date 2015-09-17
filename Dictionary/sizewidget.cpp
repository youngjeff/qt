#include "sizewidget.h"
#include "ui_sizewidget.h"
#include "mainwindow.h"
#include <QIODevice>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
SizeWidget::SizeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SizeWidget)
{
    ui->setupUi(this);
}

SizeWidget::~SizeWidget()
{
    delete ui;
}

void SizeWidget::on_sureButton_clicked()
{
    QString usreName;
    QString passWord;

    QFile  file("./usrname");


        usreName = ui->usrEdit->text();
        passWord = ui->passEdit->text();
    if(usreName == NULL || passWord == NULL)
    {
        QMessageBox::information(this,"me","please input");

    }


    if(file.open(QIODevice::Append))
    {
          // QMessageBox::information(this,"care","无法注册");
           QTextStream textStream(&file);
           textStream<<usreName<<" "<<passWord<<endl;
           file.close();
           MainWindow *mainMe;
           mainMe = new MainWindow();
           mainMe->show();
           this->close();
          // file.close();
    }


}
