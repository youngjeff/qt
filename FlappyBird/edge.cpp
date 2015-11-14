#include "edge.h"
#include "Define.h"
#include <QPainter>

Edge::Edge()
{
    m_anim.setTargetObject(this);
    m_anim.setPropertyName("pos");
    connect(&m_anim,SIGNAL(finished()),this,SLOT(BeginMove()));

}
QRectF Edge::boundingRect() const
{
    return  EDGE_BOUNDING;
}

void Edge::paint( QPainter* pPainter,
                        const QStyleOptionGraphicsItem* pOption,
                        QWidget* pWidget )
{
    Q_UNUSED(pOption);
    Q_UNUSED(pWidget);
    QPixmap src(":/edge.png");
    for(int i=0;i<EDGE_RE;i++)
    {
        pPainter->drawPixmap(i*src.width()-400,-12.5,src.width(),src.height(),src);
    }

}

void Edge::BeginMove()
{
    static int i = 0;
    if(i==0||i==1)
    {
    lastPos = this->pos();
    i++;
    }else
    {
        setPos(lastPos);
    }
    m_anim.setDuration(EDGE_BOUNDING.width()/2/SPEED*1000);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(-1*EDGE_BOUNDING.width()/2,0));
    m_anim.start();
}








