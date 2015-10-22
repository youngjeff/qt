#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "showwidget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500,400);
    this->setStyleSheet("color: black;background-color: rgb(0, 205, 255);");
    setWindowTitle("DataBase");
    usrLab = new QLabel(this);
    usrEdit = new QLineEdit(this);
    usrLab->setText("用户名");
    usrEdit->setPlaceholderText("please input your name right here");
    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(usrLab);
    hbox1->addWidget(usrEdit);

    passLab = new QLabel(this);
    passEdit = new QLineEdit(this);
    passLab->setText("密码");
    passEdit->setPlaceholderText("please input your password right here");
    passEdit->setEchoMode(QLineEdit::Password);
    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addWidget(passLab);
    hbox2->addWidget(passEdit);

    submintButton = new QPushButton(this);
    submintButton->setText("登录");
    submintButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    cancelButton  = new QPushButton(this);
    cancelButton->setText("退出");
    cancelButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    QHBoxLayout * hbox3 = new QHBoxLayout;
    hbox3->addWidget(submintButton);
    hbox3->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(hbox1);
    mainLayout->addLayout(hbox2);
    mainLayout->addLayout(hbox3);
    this->setLayout(mainLayout);

    connect(submintButton,&QPushButton::clicked,this,&Widget::subMint);
    connect(cancelButton,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{

}
void Widget::connects()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./tables");
    db.open();
}
int Widget::subMint()
{

    QString usrname ,dbname;
    QString password, dbword;

    usrname = usrEdit->text();
    password = passEdit->text();

    if(usrname == NULL || password == NULL)
    {
        QMessageBox::information(this,"show","信息未填完",QMessageBox::Ok);
        return 0;
    }else
    {
         connects();
         QSqlQuery query;
         QString usrQuery = QString("SELECT name FROM usrs WHERE name = '%1'").arg(usrname);
         query.exec(usrQuery);
         while(query.next())
         {
             dbname = query.value(0).toString();
         }
         if(dbname != usrname)
         {
             QMessageBox::information(this,"show","您还没注册");
              return 0;
         }else
         {
             QString passQuery=QString("SELECT password FROM usrs WHERE name = '%1'").arg(usrname);
             query.exec(passQuery);
             while(query.next())
             {
                 dbword = query.value(0).toString();
             }
             if(dbword != password)
             {
                 QMessageBox::information(this,"show","您的密码输入错误");
             }
             else
             {
                 ShowWidget *showWidget = new ShowWidget;
                 showWidget->show();
                 this->close();
                 return 0;
             }
         }

    }
    return 0;
}
