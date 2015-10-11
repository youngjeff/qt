#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
class Widget : public QTableWidget
{
    Q_OBJECT

public:
    Widget(QTableWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
