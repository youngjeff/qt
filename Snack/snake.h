#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QList>
#include <QGraphicsItem>
class GameController;
class Snake :public QGraphicsItem
{
public:
    enum Direction{
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    Snake(GameController & controller);
    ~Snake();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *,QWidget *);

    void setMoveDirection(Direction direction);
protected:
    void advance(int step);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void handleCollisions();

    QPointF head;
    int growing;
    int speed;
    QList<QPointF> tail;
    int tickCounter;
    Direction moveDirection;
    GameController &controller;
};

#endif // SNAKE_H
