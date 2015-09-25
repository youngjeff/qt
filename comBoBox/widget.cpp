#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(chooseId()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(quit()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::chooseId()
{
    QString outPutString;
    switch(ui->comboBox->currentIndex())
    {
        case 0:outPutString="one";break;
        case 1:outPutString="two";break;
        case 2:outPutString="three";break;
        case 3:outPutString="four";break;
    }
    if(ui->comboBox->currentIndex()==-1)
    {
        outPutString="you don't choose anyone";
    }
    QMessageBox::information(this,tr("show"),outPutString);
}
void Widget::quit()
{
    close();
}
