#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    //QWidget *widget;
    QLabel *label;
 protected:
    void mouseMoveEvent(QMouseEvent *event);//回调函数,Qwidget的虚函数
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);



};

#endif // WIDGET_H
