#include "widget.h"
#include <QKeyEvent>
#include <iostream>
using namespace std;
Widget::Widget(QTextEdit *parent) :
    QTextEdit(parent)
//?
{
    this->setMaximumSize(400,400);
    this->setMinimumSize(400,400);
   // textEdit = new QTextEdit(this);
   // textEdit->setMaximumSize(400,400);
    //textEdit->setMinimumSize(400,400);

}

Widget::~Widget()
{

}
bool Widget::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e) ;
        if(keyEvent->key() == Qt::Key_Tab){
            cout<<"you press tab";
            return true;
        }
    }
    return QWidget::event(e);
}
