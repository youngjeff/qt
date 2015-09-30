#include "eventfilter.h"

EventFilter::EventFilter(QObject *watched , QObject *parent)
    : QObject(parent)
{

}
EventFilter::~EventFilter()
{

}
bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_watched){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug()<<"QApplication::eventFilter"<<endl;
        }
    }
    return false;
}
