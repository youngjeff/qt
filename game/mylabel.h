/*------------------------------------------------------------------
 * 继承自QLabel
 * 子类化理由：启用反锯齿参数减少锯齿、几乎没效果、和普通QLabel一样使用
 * ----------------------------------------------------------------*/


#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // MYLABEL_H
