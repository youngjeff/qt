#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>

class Food :public QGraphicsItem
{
public:
    Food(qreal x,qreal y);
    ~Food();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
};

#endif // FOOD_H
