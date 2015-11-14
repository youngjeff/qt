#include "bird.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Define.h"

qreal myEasingFunction(qreal progress)
{
    return -BIRD_JUMP*(progress*progress-0.5*progress);
}

Bird::Bird()
{
    status = 0;
    m_anim.setTargetObject(this);
    m_anim.setPropertyName("pos");

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(changeStatus()));

    m_checkTimer = new QTimer(this);
    connect(m_checkTimer,SIGNAL(timeout()),this,SLOT(checkCollision()));
    m_checkTimer->start(20);
    isDied = false;
}

QRectF Bird::boundingRect() const
{
    return  BIRD_BOUNDING;
}

void Bird::paint( QPainter* pPainter,
                        const QStyleOptionGraphicsItem* pOption,
                        QWidget* pWidget )
{
    Q_UNUSED(pOption);
    Q_UNUSED(pWidget);
    QPixmap src(":/hero_1.png");
    pPainter->drawPixmap(BIRD_BOUNDING,
                         src.copy(src.width()/4*status,src.height()/2,src.width()/4,src.height()/4),
                         QRectF(5,5,src.width()/4-20,src.height()/4-20 ));
   // pPainter->drawRect(BIRD_BOUNDING);
}

void Bird::ClickToFlay()
{
    if(isDied)
        return;
    m_anim.stop();
    m_anim.setDuration(BIRD_FLAYTIME);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(0,-20));
    m_curve.setCustomType(myEasingFunction);
    m_anim.setEasingCurve(m_curve);
    m_anim.start();

    m_timer->start(BIRD_FLAYTIME/8);
    status = 0;
}

void Bird::changeStatus()
{
    status ++;
    this->scene()->views().value(0)->repaint();
    if(status == 3)
    {
        m_timer->stop();
    }
}

void Bird::checkCollision()
{
    if(this->collidingItems().size()!=0)
    {
        CollisionToDeath();
    }
}

void Bird::CollisionToDeath()
{
    m_timer->stop();
    m_checkTimer->stop();
    status = 3;
    this->scene()->views().value(0)->repaint();
    m_anim.stop();
    m_anim.setDuration(DEATH_TIME);
    m_anim.setStartValue(this->pos());
    m_anim.setEndValue(this->pos()+QPoint(0,600));
    m_anim.start();
    isDied = true;
    emit died();
}

void Bird::reBegin()
{
    m_anim.stop();
    m_checkTimer->start();
    status = 0;
    isDied = false;
    this->scene()->views().value(0)->repaint();
}







