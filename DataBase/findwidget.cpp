#include "findwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QMessageBox>
#include <QLabel>
FindWidget::FindWidget(QWidget *parent)
    :QWidget(parent)
{
    resize(500,200);
    this->setWindowTitle("查找");
    this->setStyleSheet("background-color: rgb(0, 205, 255);color:black");
    QHBoxLayout *hbox = new QHBoxLayout;
    QVBoxLayout *vbox = new QVBoxLayout;
    QHBoxLayout *findbox = new QHBoxLayout;
    QHBoxLayout *labbox = new QHBoxLayout;
    QLabel *idlabel = new QLabel;
    idlabel->setText("ID号");
    QLabel *namelabel = new QLabel;
    namelabel->setText("姓名");
    QLabel *agelabel = new QLabel;
    agelabel->setText("年龄");
    QLabel *magerlabel = new QLabel;
    magerlabel->setText("专业");
    QLabel *addlabel = new QLabel;
    addlabel->setText("城市");
    labbox->addWidget(idlabel);
    labbox->addWidget(namelabel);
    labbox->addWidget(agelabel);
    labbox->addWidget(magerlabel);
    labbox->addWidget(addlabel);
    nameEdit = new QLineEdit;
//    nameEdit->setPlaceholderText("输入姓名");
    ageEdit = new QLineEdit;
//    ageEdit->setPlaceholderText("输入年龄");
    magerEdit = new QLineEdit;
//    magerEdit->setPlaceholderText("输入专业");
    addressEdit = new QLineEdit;
    idEdit = new QLineEdit;

    findEdit = new QLineEdit;
    findEdit->setPlaceholderText("输入ID号");



    findButton = new QPushButton;
    findButton->setText("查询");
    findButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    findbox->addWidget(findEdit);
    findbox->addWidget(findButton);

    hbox->addWidget(idEdit);
    hbox->addWidget(nameEdit);
    hbox->addWidget(ageEdit);
    hbox->addWidget(magerEdit);
    hbox->addWidget(addressEdit);
    vbox->addLayout(findbox);
    vbox->addLayout(labbox);
    vbox->addLayout(hbox);

    this->setLayout(vbox);
    connect(findButton,&QPushButton::clicked,this,&FindWidget::find);
}
FindWidget::~FindWidget()
{

}
void FindWidget::find()
{
    QString findString = findEdit->text();
    int findInt;
    QSqlQuery query,querys;
    QString  queryString;
    QString  queryadd;
    int address;
        findInt = findString.toInt();
        queryString = QString("select * from student where id = %1").arg(findInt);

    query.exec(queryString);
    while(query.next())
    {
    idEdit->setText(query.value(0).toString());
    nameEdit->setText(query.value(1).toString());
    ageEdit->setText(query.value(2).toString());
    magerEdit->setText(query.value(3).toString());
    address = query.value(4).toInt();
    }
    queryadd = QString("select name from city where id = %1").arg(address);
    querys.exec(queryadd);
    while(querys.next()){
    addressEdit->setText(querys.value(0).toString());
    }
}
