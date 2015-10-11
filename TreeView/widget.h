#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QPushButton>
#include <QTreeView>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QFileSystemModel *model;
    QTreeView *treeView;
    void mkdir();
    void rm();
};

#endif // WIDGET_H
