#include "iowidget.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <QFileInfo>
#include <QtDebug>
using namespace std;
IoWidget::IoWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);
    this->setWindowTitle("open file");
    openButton = new QPushButton(this);
    openButton->setGeometry(300,100,80,30);
    openButton->setStyleSheet("background-color:cyan");
    openButton->setText("打开文件");
    readButton = new QPushButton(this);
    readButton->setGeometry(70,140,80,30);
    readButton->setText("读取文件");
    fileEdit   = new QTextEdit(this);
    fileEdit->setGeometry(70,100,200,30);
    fileEdit->setPlaceholderText("显示路径");
    connect(openButton,&QPushButton::clicked,this,&IoWidget::openfile);
    connect(readButton,&QPushButton::clicked,this,&IoWidget::readFile);

}

IoWidget::~IoWidget()
{

}
void IoWidget::openfile()
{
    openString =QFileDialog::getOpenFileName(this,"open file","./","*");
    //    QFile openFile(openString);
    fileEdit->setPlainText(openString);
}
void IoWidget::readFile()
{
    QFile file( openString);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::information(this,"worning","open file failed",QMessageBox::Ok);

    }
    else{
        while(!file.atEnd())
        {
            cout<<file.readLine().toStdString();//将数据流转变为标准字符串
        }
    }

    QFileInfo info(file);
    cout<<info.isDir()<<endl;
    cout<<info.isExecutable()<<endl;
    cout<<info.baseName().toStdString()<<endl;


    cout<<info.completeSuffix().toStdString()<<endl;

}
