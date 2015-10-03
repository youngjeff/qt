#include "paintwidget.h"
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(600,400);
    setWindowTitle("painter demo");
}

PaintWidget::~PaintWidget()
{

}
void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap  pixmap("./test.jpg");
    QBitmap  bitmap("./test.jpg");
    painter.drawPixmap(10,10,250,125,pixmap);
    painter.drawPixmap(270,10,250,125,bitmap);
    QPixmap whitePixmap("./test.jpg");
    QBitmap whiteBitmap("./test.jpg");
    painter.drawPixmap(10,140,250,125,whitePixmap);
    painter.drawPixmap(270,140,250,125,whiteBitmap);
}
