#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsObject>
#include <QPropertyAnimation>

class Edge : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES( QGraphicsItem )
    Q_PROPERTY( QPointF pos READ pos WRITE setPos )
public:
    Edge();
    QRectF	boundingRect () const;
public slots:
    void BeginMove();

protected:
    void paint( QPainter* pPainter, const QStyleOptionGraphicsItem* pOption,
                QWidget* pWidget = 0 );
private :
    QPropertyAnimation m_anim;
    QPointF lastPos;
};

#endif // EDGE_H








