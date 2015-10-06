#include <QPainter>

#include "constants.h"
#include "gamecontroller.h"
#include "snake.h"
#include <QtDebug>
#include <iostream>
using namespace std;

static const qreal SNAKE_SIZE = 10;

Snake::Snake(GameController &controller) :
    head(0, 0),
    growing(7),
    speed(3),
    moveDirection(NoMove),
    controller(controller)

{
}

QRectF Snake::boundingRect() const//oundingRect() 返回一个用于包裹住图形元素的矩形，也就是这个图形元素的范围
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();
//    cout<<1<<minX<<" "<<minY<<" "<<maxX<<" "<<maxY<<" "<<endl;
   foreach (QPointF p, tail) {
//       cout<<p.x()<<" "<<p.y()<<endl;
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }

    QPointF tl = mapFromScene(QPointF(minX, minY));//将场景坐标转为视图坐标
    QPointF br = mapFromScene(QPointF(maxX, maxY));//将场景坐标转为视图坐标
//      QPointF tl = QPointF(minX, minY);
//      QPointF br = QPointF(maxX, maxY);
//    cout<<3<<" "<<tl.x()<<" "<<tl.y()<<" "<<endl;
    QRectF bound = QRectF(tl.x(),  // x
                          tl.y(),  // y
                          br.x() - tl.x() + SNAKE_SIZE,      // width
                          br.y() - tl.y() + SNAKE_SIZE       //height
                          );
//    cout<<tl.x()<<" "<<tl.y()<<" "<<br.x()<<" "<<br.y()<<" "<< br.y() - tl.y() + SNAKE_SIZE <<endl;
    return bound;
}

QPainterPath Snake::shape() const//绘制蛇的身体
{
    QPainterPath path;
    path.setFillRule(Qt::OddEvenFill);

    path.addRect(QRectF(0, 0, SNAKE_SIZE, SNAKE_SIZE));

    foreach (QPointF p, tail) {
        QPointF itemp = mapFromScene(p);
        path.addRect(QRectF(itemp.x(), itemp.y(), SNAKE_SIZE, SNAKE_SIZE));
    }
    //将坐标变成矩形
    return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::cyan);//画出蛇
    painter->restore();
}

void Snake::setMoveDirection(Direction direction)
{
    moveDirection = direction;
}

void Snake::advance(int step)//推进
{
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        return;
    }
    if (moveDirection == NoMove) {
        return;
    }

    if (growing > 0) {
        QPointF tailPoint = head;//添加头
        tail << tailPoint;//增加尾节点 head组成尾节点
        growing -= 1;//增加的长度
//        cout<<growing<<endl;
    } else {
        tail.takeFirst();//去掉蛇尾
        tail << head;//增加蛇头节点
//        cout<<growing<<"second"<<endl;
    }

    switch (moveDirection) {
        case MoveLeft:
            moveLeft();
            break;
        case MoveRight:
            moveRight();
            break;
        case MoveUp:
            moveUp();
            break;
        case MoveDown:
            moveDown();
            break;
    }

    setPos(head);//获得头节点的坐标
    handleCollisions();//处理冲突
}

void Snake::moveLeft()
{
    head.rx() -= SNAKE_SIZE;
    if (head.rx() < -100) {
        head.rx() = 100;
    }
}

void Snake::moveRight()
{
    head.rx() += SNAKE_SIZE;
    if (head.rx() > 100) {
        head.rx() = -100;
    }
}

void Snake::moveUp()
{
    head.ry() -= SNAKE_SIZE;
    if (head.ry() < -100) {
        head.ry() = 100;
    }
}

void Snake::moveDown()
{
    head.ry() += SNAKE_SIZE;
    if (head.ry() > 100) {
        head.ry() = -100;
    }
}

void Snake::handleCollisions()
{
    QList<QGraphicsItem *> collisions = collidingItems();

    // Check collisions with other objects on screen
    foreach (QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Food) {
            // Let GameController handle the event by putting another apple
            controller.snakeAteFood(this, (Food *)collidingItem);
            growing += 1;
        }
    }

    // Check snake eating itself
    if (tail.contains(head)) {
        controller.snakeAteItself(this);
    }
}
