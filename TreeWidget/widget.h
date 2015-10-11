#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidget>
class Widget : public QTreeWidget
{
    Q_OBJECT

public:
    Widget(QTreeWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
