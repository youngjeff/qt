#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();

    ~Widget();

     QGraphicsScene *scene;
      QGraphicsView *view ;
     int time;
public slots:
    void drawAgain();
};

#endif // WIDGET_H
