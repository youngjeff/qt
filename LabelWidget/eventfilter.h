#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QtDebug>
#include <iostream>
class EventFilter :public QObject
{
public:
    EventFilter(QObject *watched,QObject *parent = 0):
        QObject(parent),
        m_watched(watched)
    {
    }
    ~EventFilter();
protected:
    bool eventFilter(QObject *watched, QEvent *event);



private:
      QObject *m_watched;
};

#endif // EVENTFILTER_H
