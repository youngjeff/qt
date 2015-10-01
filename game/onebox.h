/*-----------------------------------------------------------------------------------------------------
 * 本类继承于QGraphicsObject、用于实现方块内的小格子、以及碰撞的检测
 * --------------------------------------------------------------------------------------------------*/

#ifndef ONEBOX_H
#define ONEBOX_H

#include <QGraphicsObject>

class oneBox : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit oneBox(const QColor &color=Qt::red);
    QRectF boundingRect() const;                                                              //碰撞检测范围
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);   //格子样式设定
    QPainterPath shape() const;                                                               //碰撞检测

signals:

public slots:

private:
    QColor brushColor;
    QCursor *cursor;
};

#endif // ONEBOX_H
