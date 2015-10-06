#include <QPainter>

#include "constants.h"
#include "food.h"

static const qreal FOOD_RADIUS = 3;

Food::Food(qreal x, qreal y)
{
    setPos(x, y);
    setData(GD_Type, GO_Food);
}

QRectF Food::boundingRect() const
{
    return QRectF(-TILE_SIZE,    -TILE_SIZE,
                   TILE_SIZE * 2, TILE_SIZE * 2 );
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    int color ;
    color = (int) qrand() %5 ;
    switch (color) {
    case 0 :
        painter->fillPath(shape(), Qt::red);
        break;
    case 1:
        painter->fillPath(shape(), Qt::green);
        break;
    case 2:
        painter->fillPath(shape(),Qt::white);
        break;
    case 3:
        painter->fillPath(shape(),Qt::blue);
        break;
    case 4:
        painter->fillPath(shape(),Qt::yellow);
        break;
    default:
        break;
    }
//    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

QPainterPath Food::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}
