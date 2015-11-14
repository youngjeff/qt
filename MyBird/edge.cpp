#include "edge.h"
#include "define.h"
#include <QPainter>
edge::edge()
{
    m_anim.setTargetObject(this);
    m_anim.setPropertyName("pos");
    connect(&m_anim,SIGNAL(finished()),this,SLOT(BeginMove()));
}
QRectF edge::boundingRect() const
{
    return EDGE_BOUNDING;
}
void edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPixmap src(":/edge.png");
    for(int i=0;i<EDGE_RE;i++)
    {
        painter->drawPixmap(i*src.width()-400,-12.5,src.width(),src.height(),src);
    }
}

void edge::BeginMove()
{
    static int i = 0;
    if(i==0||i==1)
    {
        lastPos = this->pos();
        i++;
    }else{
        setPos(lastPos);
    }
    m_anim.setDuration(EDGE_BOUNDING.width()/2/SPEED*1000);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(-1*EDGE_BOUNDING.width()/2,0));
    m_anim.start();
}













