#include "widget.h"
#include <QTableWidget>
#include <QItemSelectionModel>
#include <QModelIndex>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
        this->resize(600,500);
        QTableWidget *tableWidget = new QTableWidget(this);
        tableWidget->setGeometry(0,0,600,500);
//        tableWidget->setMaximumSize(600,500);
//        tableWidget->setMinimumSize(600,500);
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(4);

        QItemSelectionModel *selectionModel = tableWidget->selectionModel();
        QModelIndex toleft = tableWidget->model()->index(0,0,QModelIndex());
        QModelIndex bottomRight = tableWidget->model()->index(5,2,QModelIndex());

        QItemSelection selection(toleft,bottomRight);
        selectionModel->select(selection,QItemSelectionModel::Select);

        QModelIndexList indexes = selectionModel->selectedIndexes();
        QModelIndex index;
        foreach (index, indexes) {
            QString text = QString().arg(index.row()).arg(index.column());
            model
        }
}


Widget::~Widget()
{

}
