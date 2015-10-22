#include "changewidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QMessageBox>
#include <QLabel>
ChangeWidget::ChangeWidget(QWidget *parent)
    :QWidget(parent)
{
    resize(500,200);
    this->setWindowTitle("修改");
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
    labbox->addWidget(idlabel);
    labbox->addWidget(namelabel);
    labbox->addWidget(agelabel);
    labbox->addWidget(magerlabel);

    nameEdit = new QLineEdit;
//    nameEdit->setPlaceholderText("输入姓名");
    ageEdit = new QLineEdit;
//    ageEdit->setPlaceholderText("输入年龄");
    magerEdit = new QLineEdit;
//    magerEdit->setPlaceholderText("输入专业");
    addressEdit = new QLineEdit;
    findEdit = new QLineEdit;
    findEdit->setPlaceholderText("输入ID");
    changeButton = new QPushButton;
    changeButton->setText("修改");
    changeButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    findButton = new QPushButton;
    findButton->setText("查询");
    findButton->setStyleSheet("background-color: rgb(15, 125, 254);");
    findbox->addWidget(findEdit);
    findbox->addWidget(findButton);

    hbox->addWidget(addressEdit);//id
    hbox->addWidget(nameEdit);
    hbox->addWidget(ageEdit);
    hbox->addWidget(magerEdit);

    vbox->addLayout(findbox);
    vbox->addLayout(labbox);
    vbox->addLayout(hbox);
    vbox->addWidget(changeButton);
    this->setLayout(vbox);
    connect(findButton,&QPushButton::clicked,this,&ChangeWidget::find);
    connect(changeButton,&QPushButton::clicked,this,&ChangeWidget::change);
}
ChangeWidget::~ChangeWidget()
{

}
void ChangeWidget::find()
{
    QString findString = findEdit->text();
    int findInt;
    QSqlQuery query;
    QString  queryString;

        findInt = findString.toInt();
        queryString = QString("select * from student where id = %1").arg(findInt);

    query.exec(queryString);
    while(query.next())
    {
    addressEdit->setText(query.value(0).toString());
    nameEdit->setText(query.value(1).toString());
    ageEdit->setText(query.value(2).toString());
    magerEdit->setText(query.value(3).toString());
}
}
void ChangeWidget::change()
{
    int adds= addressEdit->text().toInt();
    QString names = nameEdit->text();
    int      age = ageEdit->text().toInt();
    QString mager = magerEdit->text();
    QString queryString = QString("update student set id=%1 ,name='%2',age=%3,mager='%4'where id=%5")
            .arg(adds).arg(names).arg(age).arg(mager).arg(adds);
    QSqlQuery query;
    query.exec(queryString);
    QMessageBox::information(this,"yes","修改成功");

}
