#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,800);
    this->setWindowTitle("Color Whell");
}

Widget::~Widget()
{

}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    const int r = 150;
        QConicalGradient conicalGradient(150,150,0);//
//    QConicalGradient conicalGradient;
    conicalGradient.setColorAt(0.0,Qt::red);
    conicalGradient.setColorAt(60.0/360.0,Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0,Qt::cyan);
    conicalGradient.setColorAt(180.0/360.0, Qt::green);
    conicalGradient.setColorAt(240.0/360.0,Qt::blue);
    conicalGradient.setColorAt(300.0/360.0,Qt::magenta);
    conicalGradient.setColorAt(1.0,Qt::red);

//    conicalGradient.setCenter(0.0,Qt::red);
    //painter.drawEllipse(QPoint(150,150),r,r);
//    painter.translate(350,350);//平移坐标系，按给定偏移;即，给定的偏移被加到分。

    QBrush brush(conicalGradient);  //设置画刷
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
//    painter.drawEllipse(QPoint(0,0),r,r);

    painter.drawEllipse(QPoint(150,150),r,r);
//    painter.drawEllipse(QPoint(0,-150),r,r);
//    painter.drawEllipse(QPoint(-150,0),r,r);
//    painter.drawEllipse(QPoint(0,150),r,r);
//    painter.drawEllipse(QPoint(-150,-150),r,r);
//    painter.drawRect(-350,-350,800,800);
//    painter.drawRect(0,0,800,800);

     QLinearGradient linearGradient(200,200,300,300);//
     linearGradient.setColorAt(0.2,Qt::white);
     linearGradient.setColorAt(0.6,Qt::green);
     linearGradient.setColorAt(1.0,Qt::black);
     painter.setBrush(QBrush(linearGradient));
     painter.drawEllipse(200,200,200,150);
     //Constructs a linear gradient with interpolation area between (x1, y1) and (x2, y2).
}
