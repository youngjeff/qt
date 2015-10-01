#include "paintwidget.h"

#include <QPainter>
#include <QPen>
PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,600);
    setWindowTitle("paint demo");
}

PaintWidget::~PaintWidget()
{

}
void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(200,100,200,500);  // 画条直线
    painter.drawLine(100,200,600,200);  // 画条直线

    painter.setPen(Qt::black);  //设置颜色
    //    painter.drawRect(10,10,100,400);  //画个矩形
    painter.setPen(QPen(Qt::green,5));  //设置画刷,宽度为5
    painter.setBrush(Qt::blue);     //设置填充为蓝色
    painter.drawEllipse(200,200,400,400);    //画一个椭圆
//    painter.drawRect(10,10,100,400);
     painter.drawLine(100,400,800,400);
      painter.drawLine(400,100,400,600);

}
//paintEvent
