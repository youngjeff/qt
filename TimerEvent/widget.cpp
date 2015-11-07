#include "widget.h"
#include <QStyle>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(300,300);
    lcdNumber = new QLCDNumber(this);
    lcdNumber->setGeometry(0,0,300,300);
    lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerUpdate);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    timer->start(0);
    timer->setInterval(1000);
}

Widget::~Widget()
{

}
void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if((time.second() % 2 )==0) text[2]=' ';
    lcdNumber->display(text);
    //int rand = qrand() % 300;
    //lcdNumber->move(rand,rand);
}
