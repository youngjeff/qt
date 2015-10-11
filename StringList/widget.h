#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QStringListIterator>
#include <QStringListModel>
#include <QListView>
#include <QModelIndex>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QStringListModel *model;
    QListView *listView;
    void insertData();
    bool insertRows(int row,int conut,const QModelIndex &parent = QModelIndex());
//    void insertData();
    void deleteData();
    void showData();
};

#endif // WIDGET_H
