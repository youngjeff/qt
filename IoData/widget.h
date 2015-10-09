#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDataStream>
#include <QFile>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *openButton;
private slots:
    void onShow();
};

#endif // WIDGET_H
