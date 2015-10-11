#include "widget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>

Widget::Widget(QTreeWidget *parent)
    : QTreeWidget(parent)
{
    resize(400,300);
//    QTreeWidget treeWidget;
//    treeWidget.setColumnCount(1);
    this->setColumnCount(1);
    QTreeWidgetItem *root = new QTreeWidgetItem(this,QStringList(QString("root")));
    new QTreeWidgetItem(root,QStringList(QString("Leaf 1")));
    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root,QStringList(QString("2")));
    leaf2->setCheckState(0,Qt::Checked);
    QTreeWidgetItem *leaf3 = new QTreeWidgetItem(leaf2,QStringList(QString("leaf3")));//容器list
//    QList<QTreeWidgetItem *>rootList;//这是两种模式,(2)新建一个list(qtreewidgetitem类型),
//    rootList << root;//将root放入list
//    this->insertTopLevelItems(0,rootList);//将list插入到qtreewidget

//    treeWidget.show();

}

Widget::~Widget()
{

}
