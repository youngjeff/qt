#include "widget.h"

Widget::Widget()
{
    scene = new QGraphicsScene;

    //    scene = new QGraphicsScene(this);
    scene->addEllipse(0,0,50,50,QPen(Qt::red),QBrush(Qt::blue));
    //    QGraphicsView view(scene);
    //    view(this)
    //    this->
    view = new QGraphicsView(scene,this);
    //    view->setWindowTitle("show me");
    view->resize(900,400);
    view->show();
    time = 0;
    QTimer::singleShot(1000,,SLOT(Widget::drawAgain));
}

Widget::~Widget()
{

}
void Widget::drawAgain()
{
    time += 100;
    scene->addEllipse(time,time,50,50,QPen(Qt::red),QBrush(Qt::blue));

}
