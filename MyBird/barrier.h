#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QTimer>
#include "define.h"

class barrier : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    barrier();
    QRectF boundingRect() const;
    bool isMain;
    QPointF lastPos;
    void reBegin();

public slots:
    void BeginMove();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0);

private:
    static int randValue;
    QPropertyAnimation m_anim;
};

#endif // BARRIER_H


















