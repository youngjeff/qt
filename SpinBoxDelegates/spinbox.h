#ifndef SPINBOX_H
#define SPINBOX_H
#include <QStyledItemDelegate>
#include <QWidget>
#include <QStyleOptionViewItem>
#include <QModelIndex>

class SpinBox : public QStyledItemDelegate
{
    Q_OBJECT
public :
    QStyledItemDelegate(QObject *parent = 0) : QStyledItemDelegate(parent){}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const;

    void setModelData(QWidget *editor,QAbstractItemModel *model,const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const ;

};


#endif // SPINBOX_H
