#include "paintwidget.h"

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
    painter.setPen(QPen(Qt::black,5,Qt::DashDotDotLine,Qt::RoundCap));
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(50,150,200,150);

    painter.setRenderHint(QPainter::Antialiasing,true);//右侧的图形增加了抗锯齿效果
    painter.setPen(QPen(Qt::black,5,Qt::DashDotDotLine,Qt::RoundCap));
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(300,150,200,150);
}
//Qpainter是一个状态机,如果不去改变它,他将维持原来的状态
