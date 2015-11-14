#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsObject>
#include <QPropertyAnimation>

class edge : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    Q_PROPERTY( QPointF pos READ pos WRITE setPos )

public:
    edge();
    QRectF boundingRect() const;
public slots:
    void BeginMove();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0);
private:
    QPropertyAnimation m_anim;
    QPointF lastPos;
};

#endif // EDGE_H
