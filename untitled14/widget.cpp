#include "widget.h"
#include "ui_widget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>
#include <iostream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QTableView *view = new QTableView(this);


    if(connect())
    {
          QSqlTableModel *model = new QSqlTableModel;
        model->setTable("usrname");
        model->setSort(1,Qt::AscendingOrder);
        model->setHeaderData(2,Qt::Horizontal,"Name");
        model->setHeaderData(3,Qt::Horizontal,"Age");
        model->setHeaderData(4,Qt::Horizontal,"likes");
        model->select();

        ui->tableView->setModel(model);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//选择行
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑?
         QHeaderView *header =  ui->tableView->horizontalHeader();
       header->setStretchLastSection(true);
    }
}

Widget::~Widget()
{
    delete ui;
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
