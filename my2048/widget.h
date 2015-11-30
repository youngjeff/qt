#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QDesktopWidget>
#include <QTime>
#include <QtMath>
#include <QKeyEvent>
#include <QPainter>
#include <QRectF>
#include <QFont>
#include <QPen>
#include <QPushButton>
#include <QLabel>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    int array[4][4];
    int arrayprey[4][4];
    int score;
    qreal rectSize;
    QColor bk;
    QColor bkColor[16];
    QColor ftColor[16];
    bool  isGameOver();
    bool  isok;
    void  rebegin();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent * event);
};

#endif // WIDGET_H
