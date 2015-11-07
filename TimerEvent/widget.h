#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QtGlobal>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QTimer *timer;
    QLCDNumber *lcdNumber;
    void timerUpdate();


};

#endif // WIDGET_H
