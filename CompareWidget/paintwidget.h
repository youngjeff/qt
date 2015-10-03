#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPaintEvent>
class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);
    ~PaintWidget();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTWIDGET_H
