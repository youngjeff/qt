#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
using namespace  std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QFile dataFile("./data");
    dataFile.open(QIODevice::ReadWrite);
    QTextStream textStream(&dataFile);
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./dics");
    database.open();
    int IDnumber = 1;
    QString english,chinese;
    while(!textStream.atEnd())
    {
        textStream >> english;
        chinese = textStream.readLine();
         QSqlQuery ql;
//         ql.prepare("INSERT INTO words (ID,endlish,chinese) VALUES(?,?,?)");
        QString query = QString("INSERT INTO words (ID,english,chinese) VALUES('%1','%2','%3')").arg(IDnumber).arg(english).arg(chinese);
//        QString query= QString("INSERT INTO words (ID , engligh, chinese) VALUES('" + IDnumber + "','" + english + "','" + chinese +  "')");

        ql.exec(query);
        IDnumber++;
//        cout<<IDnumber<<english.toStdString()<<chinese.toStdString()<<endl;
        cout<<query.toStdString()<<endl;
    }

}
