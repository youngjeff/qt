#include "mylabel.h"
#include <QPainter>

myLabel::myLabel(QWidget *parent) :
    QLabel(parent)
{
}

void myLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform|QPainter::Antialiasing);
    QLabel::paintEvent(event);
}
