#include "widget.h"
#include <QFileDialog>
#include <iostream>
#include <QtDebug>
#include <QTextStream>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);
    openButton = new QPushButton(this);
    openButton->setGeometry(150,150,100,50);
    connect(openButton,&QPushButton::clicked,this,&Widget::onShow);


}

Widget::~Widget()
{

}
void Widget::onShow()
{
    QString path = QFileDialog::getOpenFileName(this,"show me","/home/jeff","*");
    QFile openFile(path);
//    openFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    openFile.open( QIODevice::ReadWrite |QIODevice::Append);

    /*QDataStream stream(&openFile);
    QString str = "the answer is 42";
    QString stout;
    stream << str;
    openFile.flush();
    stream.device()->seek(0);
    stream >> stout;
    if(stout !="")
    {
        cout<<"yes";

    }
    else
    {
        cout<<"no";
    }*/
    QTextStream stream(&openFile);
    stream <<bin<<12345678; //二进制输出
//    stream.setIntegerBase(2);
    QString string;
    QTextStream(&string, )>>oct<<31;
}
//>> 后面是变量,<<后面是值
