#include "widget.h"
#include <QTextEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600,400);
    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0,0,600,300);
    textEdit->setStyleSheet("background-color:red");
    button = new QPushButton(this);
    button->setGeometry(0,300,600,100);
    button->setStyleSheet("background-color:blue");
    button->setText("clicked");
    connect(button,&QPushButton::clicked,this,&Widget::test);

}

Widget::~Widget()
{

}
void Widget::test()
{
    QString Test = "qwerertytu";
//    textEdit->setText(Test);
    textEdit->append(Test);

}
