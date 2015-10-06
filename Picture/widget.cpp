#include "widget.h"
#include <QPushButton>
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    resize(800,600);
    QPushButton *pushButton = new QPushButton(this);
//    pushButton->setGeometry(10,10,200,200);
    pushButton->setText("show me");
    pushButton->setStyleSheet("QPushButton {color:red}");
    QLabel *label = new QLabel(this);
//    QWidget myImage ;
//    myImage.show();
    QPicture picture;
    picture.load("drawing.pic");
    QPainter painter;
    painter.begin(label);
    painter.drawPicture(0,0,picture);
    painter.end();
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPicture picture;
    QPainter painter;
    painter.begin(&picture); //在picture里面进行绘制
    painter.drawEllipse(10,20,80,70);
    painter.end();
    picture.save("drawing.pic");

}
