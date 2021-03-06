#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsItem>
#include <QPropertyAnimation>
#include <QTimer>

class Bird : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES( QGraphicsItem )
    Q_PROPERTY( QPointF pos READ pos WRITE setPos )
public:
    Bird();
    QRectF	boundingRect () const;
    void reBegin();
    bool isDied;
public slots:
    void ClickToFlay();
    void changeStatus();
    void checkCollision();
    void CollisionToDeath();
protected:
    void paint( QPainter* pPainter, const QStyleOptionGraphicsItem* pOption,
                QWidget* pWidget = 0 );
private :
    int status;
    QPropertyAnimation m_anim;
    QEasingCurve m_curve;
    QTimer *m_timer;
    QTimer *m_checkTimer;

signals:
    void died();
};

#endif // BIRD_H








