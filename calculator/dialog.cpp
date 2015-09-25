#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    sum=0;
    //temp=0;
    connect(ui->b1PushButton,SIGNAL(clicked()),this,SLOT(b1clicked()));
    connect(ui->b2PushButton,SIGNAL(clicked()),this,SLOT(b2clicked()));
    connect(ui->b3PushButton,SIGNAL(clicked()),this,SLOT(b3clicked()));
    connect(ui->b4PushButton,SIGNAL(clicked()),this,SLOT(b4clicked()));
    connect(ui->b5PushButton,SIGNAL(clicked()),this,SLOT(b5clicked()));
    connect(ui->b6PushButton,SIGNAL(clicked()),this,SLOT(b6clicked()));
    connect(ui->b7PushButton,SIGNAL(clicked()),this,SLOT(b7clicked()));
    connect(ui->b8PushButton,SIGNAL(clicked()),this,SLOT(b8clicked()));
    connect(ui->b9PushButton,SIGNAL(clicked()),this,SLOT(b9clicked()));
    connect(ui->b0PushButton,SIGNAL(clicked()),this,SLOT(b0clicked()));
    connect(ui->b00pushButton,SIGNAL(clicked()),this,SLOT(b00clicked()));
    connect(ui->addpushButton,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->subpushButton,SIGNAL(clicked()),this,SLOT(sub()));
    connect(ui->multipushButton,SIGNAL(clicked()),this,SLOT(multi()));
    connect(ui->divpushButton,SIGNAL(clicked()),this,SLOT(div()));
    connect(ui->equesPushButton,SIGNAL(clicked()),this,SLOT(equls()));
    connect(ui->quitpushButton,SIGNAL(clicked()),this,SLOT(quit()));
    connect(ui->clearPushButton,SIGNAL(clicked()),this,SLOT(clear()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::b1clicked()
{
    sum=sum*10+1;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b2clicked()
{
    sum=sum*10+2;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b3clicked()
{
    sum=sum*10+3;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b4clicked()
{
    sum=sum*10+4;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b5clicked()
{
    sum=sum*10+5;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b6clicked()
{
    sum=sum*10+6;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b7clicked()
{
    sum=sum*10+7;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b8clicked()
{
    sum=sum*10+8;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b9clicked()
{
    sum=sum*10+9;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b0clicked()
{
    if(sum!=0)
        sum=sum*10;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::b00clicked()
{
    if(sum!=0)
        sum=sum*100;
    QString SUM=QString::number(sum);
    ui->addLineEdit->setText(SUM);
}
void Dialog::add()
{
    result=sum;
    temp=1;
    sum=0;
    ui->addLineEdit->setText("+");
}
void Dialog::sub()
{
    result=sum;
    temp=2;
    sum=0;
    ui->addLineEdit->setText("-");
}
void Dialog::multi()
{
    result=sum;
    temp=3;
    sum=0;
    ui->addLineEdit->setText("*");
}
void Dialog::div()
{
    result=sum;
    temp=4;
    sum=0;
    ui->addLineEdit->setText("/");
}
void Dialog::equls()
{
    switch(temp){
    case 1:
        result+=sum;
        break;
    case 2:
        result-=sum;
        break;
    case 3:
        result*=sum;
        break;
    case 4:
        result/=sum;
        break;
    }
    QString SUM=QString::number(result);
    ui->reslutLineEdit->setText(SUM);
}
void Dialog::quit()
{
    close();
}
void Dialog::clear()
{
    sum=0;
    temp=0;
    result=0;
    ui->addLineEdit->clear();
    ui->reslutLineEdit->clear();
}
