#include "barrier.h"
#include <QPainter>
int barrier::randValue = 0;
barrier::barrier()
{

    m_anim.setTargetObject(this);
    m_anim.setPropertyName("pos");
    isMain = false;

    connect(&m_anim,SIGNAL(finished()),this,SLOT(BeginMove()));
}

QRectF barrier::boundingRect() const
{
    return BARRIER_BOUNDING;
}

void barrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPixmap src(":/barrier.png");
    painter->drawPixmap(BARRIER_BOUNDING.toRect(),src);

}
void barrier::BeginMove()
{
    if(isMain)
    {
        randValue = qrand() % DIFFICULTY - DIFFICULTY /2;
    }
    setPos(lastPos + QPointF(0,randValue));
    m_anim.setDuration((EDGE_BOUNDING.width()/2+BARRIER_BOUNDING.width())/SPEED*1000);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(-EDGE_BOUNDING.width()/2-BARRIER_BOUNDING.width(),0));
    m_anim.start();
}
void barrier::reBegin()
{
    setPos(lastPos);
    m_anim.stop();
}




















