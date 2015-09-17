
#include "prograssbar.h"
#include <QProgressBar>
#include <QWidget>
#include <QTimer>
#include "widget.h"


PrograssBar::PrograssBar(QWidget *parent) : QWidget(parent)
{

   // QWidget *widgetMe = new QWidget;
    widgetMe->resize(800,800);
    widgetMe->show();
    //this->resize(800,800);
    //prograssBarMe = new QProgressBar(this);
    prograssBarMe->setRange(0,100);
    prograssBarMe->setValue(0);
    value = 0;
    QTimer *timer = new QTimer(this);

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timeMe()));
    timer->setInterval(1000);
    timer->start();

}
void PrograssBar::timeMe()
{   if (value < 100)
    {
        value +=10;
        prograssBarMe->setValue(value);
    }
    else
    {
        Widget *widgetMe = new Widget();
        widgetMe->show();
        close();
    }
}
