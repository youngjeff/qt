#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>
#include <QStringListModel>
#include <QListView>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QStyleOptionViewItem>
class SpinBoxDelegate : public QWidget
{
    Q_OBJECT

public:
    SpinBoxDelegate(QWidget *parent = 0);
    ~SpinBoxDelegate();
    QStringListModel *model;
    QListView *listView;
    void showModel();

};

#endif // SPINBOXDELEGATE_H
