#include <QPainter>
#include <QCursor>
#include "onebox.h"

oneBox::oneBox(const QColor &color) :
    brushColor(color)
{
    cursor=new QCursor(QPixmap(":/new/prefix1/test.png"));
    setCursor(*cursor);
}


QRectF oneBox::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(-10-penWidth/2,-10-penWidth/2,20+penWidth,20+penWidth);
}

void oneBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10,-10,20,20,QPixmap(":/new/prefix1/images/box.gif"));
    painter->setBrush(brushColor);
    QColor penColor=brushColor;
    penColor.setAlpha(20);
    painter->setPen(penColor);
    painter->drawRect(-10,-10,20,20);
}

QPainterPath oneBox::shape() const
{
    QPainterPath path;
    path.addRect(-9.5,-9.5,19,19);
    return path;
}
