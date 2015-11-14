#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QTimer>
#include "Define.h"

class Barrier : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES( QGraphicsItem )
    Q_PROPERTY( QPointF pos READ pos WRITE setPos )
public:
    Barrier();
    QRectF	boundingRect () const;
    bool isMain;
    QPointF lastPos;
    void reBegin();

public slots:
    void BeginMove();

protected:
    void paint( QPainter* pPainter, const QStyleOptionGraphicsItem* pOption,
                QWidget* pWidget = 0 );
private :
    static int randValue;
    QPropertyAnimation m_anim;
};

#endif // BARRIER_H
