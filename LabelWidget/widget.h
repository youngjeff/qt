#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QObject>
#include <QtDebug>
#include <iostream>
#include <QMessageBox>
using namespace std;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    bool eventFilter(QObject *watched, QEvent *event);

protected:
    void mousePressEvent(QMouseEvent *);
    bool event(QEvent *e);

};

#endif // WIDGET_H
class EventFilter : public QObject
{
public:
    EventFilter(QObject *watched, QObject *parent = 0) :
        QObject(parent),
        m_watched(watched)
    {
    }

    bool eventFilter(QObject *watched, QEvent *event)
    {
        if (watched == m_watched) {
            if (event->type() == QEvent::MouseButtonPress) {
                cout<< "QApplication::eventFilter"<<endl;
//                QMessageBox::information(,tr("show me"),tr("QApplication::eventFilter"));
            }
        }
        return false;
    }

private:
    QObject *m_watched;
};
