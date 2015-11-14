#include "barrier.h"
#include <QPainter>

int Barrier::randValue = 0;

Barrier::Barrier()
{
    m_anim.setTargetObject(this);
    m_anim.setPropertyName("pos");
    isMain = false;

    connect(&m_anim,SIGNAL(finished()),this,SLOT(BeginMove()));
}

QRectF Barrier::boundingRect() const
{
    return  BARRIER_BOUNDING;
}

void Barrier::paint( QPainter* pPainter,
                        const QStyleOptionGraphicsItem* pOption,
                        QWidget* pWidget )
{
    Q_UNUSED(pOption);
    Q_UNUSED(pWidget);
    QPixmap src(":/barrier.png");
    pPainter->drawPixmap(BARRIER_BOUNDING.toRect(),src);
}

void Barrier::BeginMove()
{
    if(isMain)
    {
        randValue = qrand() % DIFFICULTY-DIFFICULTY/2;
    }
    setPos(lastPos+QPointF(0,randValue));
    m_anim.setDuration((EDGE_BOUNDING.width()/2+BARRIER_BOUNDING.width())/SPEED*1000);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(-EDGE_BOUNDING.width()/2-BARRIER_BOUNDING.width(),0));
    m_anim.start();
}

void Barrier::reBegin()
{
    setPos(lastPos);
    m_anim.stop();
}









