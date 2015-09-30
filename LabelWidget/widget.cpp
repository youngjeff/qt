#include "widget.h"
#include <QEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->installEventFilter(this);

}

Widget::~Widget()
{

}
bool Widget::eventFilter(QObject *watched, QEvent *event)//watched监控的对象,event事件
{

        if(watched == this)
        {
            if(event->type() == QEvent::MouseButtonPress){
                cout<<"eventFilter"<<endl;
//                QMessageBox::information(this,tr("show me"),tr("eventFilter"));

            }
        }
        return false;

}
void Widget::mousePressEvent(QMouseEvent *)//事件的具体操作
{
    cout<<"mousePressEvent"<<endl;
//    QMessageBox::information(this,tr("show me"),tr("mousePressEvent"));

}
bool Widget::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress){
        cout<<"event"<<endl;
//        QMessageBox::information(this,tr("show me"),tr("event"));

    }
    return QWidget::event(e);
}
