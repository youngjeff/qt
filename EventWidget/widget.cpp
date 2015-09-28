#include "widget.h"

#include <QLabel>
#include <QMouseEvent>
#include <QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //widget = new QWidget;
    this->setMaximumSize(300,300);
    this->setMinimumSize(300,300);
    label = new QLabel(this);
    label->setMaximumSize(300,300);//设置label的大小
    label->setMinimumSize(300,300);
    label->setMouseTracking(true);//设置label的移动
}

Widget::~Widget()
{

}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    label->setText(QString("<center><h1>Move: (%1,%2)</h1></center>").arg(QString::number(event->x()),QString::number(event->y())));//Qlabel支持html (%1,%2)
    //占位符,用于arg()

}
void Widget::mousePressEvent(QMouseEvent *event)
{
    label->setText(QString("<center><h1>Pressw:(%1,%2)</h1></center>").arg(QString::number(event->x()),QString::number(event->y())));
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Press: (%d,%d)</h1</center>",event->x(),event->y());
    label->setText(msg);
}
