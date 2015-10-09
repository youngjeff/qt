#include "widget.h"

#include <QList>
#include <QListIterator>
#include <QtDebug>
#include <QTextEdit>
#include <QPushButton>
#include <QLinkedList>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);
//    QList<QString> list; //创建容器list
    textedit = new QTextEdit(this);
    textedit->setGeometry(0,0,400,200);
    button = new QPushButton(this);
    button->setGeometry(0,200,400,100);


    /*QListIterator<QString> i(list);//创建遍历器 这是只写遍历器

    QString outString = "";
    while(i.hasNext())
    {
        outString += i.next();
    }
    while (i.hasPrevious()) {
        outString += i.previous();
    }
    outString += "\n";*/
//    textedit->setPlainText(outString);

    connect(button,&QPushButton::clicked,this,&Widget::onSet);
}

Widget::~Widget()
{

}
void Widget::onSet()
{
//    QList<QString> list;
//    list <<"A"<<"B"<<"C"<<"D";
//    QListIterator<QString> i(list);//创建遍历器 这是只写遍历器

//    QString outString = "";
   /* while(i.hasNext())
    {
        outString += i.next();
    }
    while (i.hasPrevious()) {
        outString += i.previous();
    }
//    outString += "\n";
   textedit->setPlainText(outString);*/
    QLinkedList<QString> list;
    list <<"A" <<"B"<<"C"<<"D";
    QString str = "";
    QString word;
    foreach (str, list) {
        str += "A";
        word+=str;
    }
    textedit->setPlainText(word);
}
