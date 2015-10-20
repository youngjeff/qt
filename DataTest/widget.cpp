#include "widget.h"
#include <QObject>
#include <QSqlError>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QStringList>
#include <QtDebug>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(600,400);
    dbButton = new QPushButton(this);
    dbButton->setGeometry(0,0,200,40);//让button居中心,/3
    selectButton = new QPushButton(this);
    selectButton->setGeometry(200,0,200,40);
    textedit = new QTextEdit(this);
    textedit->setGeometry(0,40,600,300);
    connect(dbButton,&QPushButton::clicked,this,&Widget::connects);
    connect(selectButton,&QPushButton::clicked,this,&Widget::selects);
}

Widget::~Widget()
{

}
void Widget::connects()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
//    db.setHostName("host");
//    db.setDatabaseName("dbname");
//    db.setUserName("usrname");
//    db.setPassword("password");
    db.setDatabaseName("./information");//我们的数据库文件
    if(!db.open()){
        QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
    }
}
void Widget::selects()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Student (name ,age ) VALUES (?,?)");//query.exec();准备输出
    QVariantList names;//链表
    names <<"Tom "<< "Jacks" << "Jane" << "Jerry";
    query.addBindValue(names);//添加绑定链表
    QVariantList ages;
    ages << 20 << 23 << 22 << 25;
    query.addBindValue(ages);//按顺序添加绑定age
    if(!query.execBatch()){//批处理函数值
        QMessageBox::critical(0,QObject::tr("Databases Error"),query.lastError().text());
    }
    query.finish();
    QString janes = "jane";
    QString jane =QString("SELECT  sex FROM Student WHERE name = '%1'").arg(janes);
    query.exec(jane);//执行完这句话,
    QString name,sex;
    while (query.next())
    {
         //name = query.value(0).toString();
          sex = query.value(0).toString();
//        cout<<name.toStdString() <<":"<<age.toStdString()<<endl;
          cout<<sex.toStdString()<<endl;
    }
//    cout<<name.toStdString() <<":"<<age.toStdString()<<endl;
}
//数据库里面的值都是list容器的形式存储
