#include "widget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>
#include <iostream>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);
    if(connect())
    {
        QTableView *view = new QTableView(this);
        QSqlRelationalTableModel *model = new QSqlRelationalTableModel;//要先有数据才能创建model,也就是先连接数据库局
        view->setGeometry(0,0,400,300);

        view->setModel(model);
        model->setTable("student");
        model->setSort(0,Qt::AscendingOrder);
//        model->setHeaderData(0,Qt::Horizontal,"Name");//from 0
//        model->setHeaderData(1,Qt::Horizontal,"Age");
//        model->setHeaderData(2,Qt::Horizontal,"likes");
        model->setRelation(3,QSqlRelation("city","id","name"));
        model->select();


//        view->setModel(model);

        view->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式
        view->setSelectionBehavior(QAbstractItemView::SelectRows);//选择行
//        view->resizeColumnsToContents();//tiaozhengziti
        view->setEditTriggers(QAbstractItemView::DoubleClicked);//不可编辑?

        QHeaderView *header =  view->horizontalHeader();
        header->setStretchLastSection(true);
        view->setItemDelegate(new QSqlRelationalDelegate(view));
//        QHeaderView *head = view->verticalHeader();
//        head->setStretchLastSection(true);
//        view->show();
//        this?->show();
    }
}

Widget::~Widget()
{

}
bool Widget::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./usr");
    if(db.open())
    {
//        QMessageBox::information(this,"yes","yes");
//        cout<< "asdasd"<<endl;
//        QSqlQuery qu;
//        qu.exec("select * from usrname ");
//        while(qu.next())
//        {
//            cout <<qu.value(0).toString().toStdString()<<endl;
//        }
        return true;
    }
    else{
        QMessageBox::information(this,"no","no");
    }
    return false;
}
