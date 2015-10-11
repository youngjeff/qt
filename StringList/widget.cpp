#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList data;
    data << "Letter A" <<"Letter B" << "Letter C"<<"Letter D";
    model = new QStringListModel(this);//字符串列表的模型
    model->setStringList(data);//将数据放到model

    listView = new QListView(this);//清单视图
    listView->setModel(model);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    QPushButton *insertBtn = new QPushButton(tr("insert"),this);
    connect(insertBtn,&QPushButton::clicked,this,&Widget::insertData);
    QPushButton *delBtn = new QPushButton(tr("Delete"),this);
    connect(delBtn,&QPushButton::clicked,this,&Widget::deleteData);
    QPushButton *showBtn = new QPushButton(tr("Show"),this);
    connect(showBtn,&QPushButton::clicked,this,&Widget::showData);
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);

}

Widget::~Widget()
{

}

void Widget::insertData()
{
    bool isOK;
    QString text = QInputDialog::getText(this,"Insert","Please input new data:",QLineEdit::Normal,"You are inserting new data",&isOK);

    //QIuputDialog 和QFileDialog类似
    if(isOK)
    {
        int row = listView->currentIndex().row();//当前的行数
        model->insertRows(row,1);
        QModelIndex index = model->index(row);//定位数据
        model->setData(index,text);//添加值
//        listView->setCurrentIndex(index);//设置当前的行数
//        listView->edit(index);
    }
}

void Widget::deleteData()
{
         if(model->rowCount() > 1)
         {
             model->removeRows(listView->currentIndex().row(),1);
         }
}

void Widget::showData()
{
    QStringList data = model->stringList();
    QString str;
    foreach (QString  s, data) {
        str += s + "\n";
    }
    QMessageBox::information(this,"Data",str);
}
