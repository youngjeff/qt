#include "widget.h"

Widget::Widget(QTableWidget *parent)
    : QTableWidget(parent)
{
    this->setWindowTitle("tableWidget");
    this->resize(600,300);
    this->setColumnCount(4);//添加列数
    this->setRowCount(5);//添加行数

    QStringList headers;
    headers <<"ID"<<"Name"<<"Age"<<"Sex";//添加标题
    this->setHorizontalHeaderLabels(headers);

    this->setItem(0,0,new QTableWidgetItem(QString("001")));//添加内容
    this->setItem(1,0,new QTableWidgetItem(QString("002")));
    this->setItem(2,0,new QTableWidgetItem(QString("003")));
    this->setItem(3,0,new QTableWidgetItem(QString("004")));
    this->setItem(4,0,new QTableWidgetItem(QString("005")));
    this->setItem(0,0,new QTableWidgetItem(QString("20100112")));



}

Widget::~Widget()
{

}
