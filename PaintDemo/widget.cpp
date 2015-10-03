#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,400);
    setWindowTitle("Paint demo");
}

Widget::~Widget()
{

}
void Widget::paintEvent(QPaintEvent *)
{
    /*QPainter painter(this);
    painter.fillRect(10,10,50,100,Qt::red);
    painter.save();//将当前状态压入栈
    painter.translate(100,0);
    painter.fillRect(10,10,50,100,Qt::yellow);
    painter.restore();//恢复上一次的状态
    painter.save();
    painter.translate(300,0);
    painter.rotate(30);
    painter.fillRect(10,10,50,100,Qt::green);
    painter.restore();
    painter.save();
    painter.translate(400,0);
    painter.scale(2,3);
    painter.fillRect(10,10,50,100,Qt::blue);
    painter.restore();
    painter.save();
    painter.translate(600,0);
    painter.shear(0,1);
    painter.fillRect(10,10,50,100,Qt::cyan);
    painter.restore();*/
    QPainter painter(this);
//    painter.setWindow(0,0,300,300);//口坐标（也就是物理坐标）和窗口坐标是一个简单的线性变换。比如一个 400×400 的窗口，我们添加如下代码：
    painter.setViewport(0,0,200,200);//物理坐标
    painter.fillRect(0,0,200,200,Qt::red);

}
