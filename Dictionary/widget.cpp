#include "widget.h"
#include "ui_widget.h"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
//QString Widget::nodes[10000] = NULL;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Node nodes[10000];
    valuess = 0;
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(valuess);
    //connect(ui->UpButton,SIGNAL(clicked(bool),this,SLOT(prograss());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->textEdit->clear();

    //ui->progressBar->setRange(0,6700);
    //ui->progressBar->setValue(valuess);
    number = 0;
    Node nodes[15];
    //Widget::nodes[10000];
    QFile inFile("./data");
   // QString sentens="好好学习,天天向上";
    //ui->textEdit->setPlainText(sentens);
    if(inFile.open(QIODevice::ReadWrite))
    {
        QTextStream textStream(&inFile);
        for (int i = number; i < number + 15; i++)
        {
            textStream>>nodes[i].word;
            //textStream>>nodes[i].explain;
            //nodes[j].explain = textStream.readLine();
            nodes[i].explain = textStream.readLine();
            ui->textEdit->append(nodes[i].word+"          "+nodes[i].explain);
        }
        number += 15;
    }

}

void Widget::on_UpButton_clicked()
{
    Node nodes[15];
    QString temp1, temp2;
    //Widget::nodes[10000];
    if(number == 15)
    {
        QMessageBox::information(this,"me","这是第一页");
    }
    else
    {
        ui->textEdit->clear();
        int i = 0, j;
        QFile inFile("./data");
        QTextStream textstream(&inFile);
        if(inFile.open(QIODevice::ReadWrite))
        {
           //QTextStream textstream(&inFile);
           for(j = 0;j < number-30; j++){
             textstream>>temp1;
             temp2 = textstream.readLine();
           }
           for(i = 0;i < 15;i++)
           {
               textstream>>nodes[i].word;
               nodes[i].explain = textstream.readLine();
               ui->textEdit->append(nodes[i].word+"          "+nodes[i].explain);
           }
        }
        number= number - 15;
        valuess--;
        //ui->progressBar->valueChanged(valuess);

        ui->progressBar->setValue(valuess);
    }

}

void Widget::on_DownButton_clicked()
{
    Node nodes[15];
    QString temp1, temp2;
    //Widget::nodes[10000];
    if(number == 6680)
    {
        QMessageBox::information(this,"me","这是最后一页");
    }
    else
    {
        ui->textEdit->clear();
        int i = 0, j;
        QFile inFile("./data");
        QTextStream textstream(&inFile);
        if(inFile.open(QIODevice::ReadWrite))
        {
           //QTextStream textstream(&inFile);
           for(j = 0;j < number; j++){
             textstream>>temp1;
             temp2 = textstream.readLine();
           }
           for(i = 0;i < 15;i++)
           {
               textstream>>nodes[i].word;
               nodes[i].explain = textstream.readLine();
               ui->textEdit->append(nodes[i].word+"          "+nodes[i].explain);
           }
        }
        number= number + 15;
        valuess++;
       // ui->progressBar-
        if(valuess == 100)
            valuess = 0;
        ui->progressBar->setValue(valuess);
    }


}

void Widget::on_reviewButton_clicked()
{
        Node nodes[10000];
        // QString temp1, temp2;
        //Widget::nodes[10000];
        int numbers = number;
        ui->textEdit->clear();
        int  j;
        QFile inFile("./data");
        QTextStream textstream(&inFile);
        if(inFile.open(QIODevice::ReadWrite))
        {
           //QTextStream textstream(&inFile);
           for(j = 0;j < numbers; j++){
               textstream>>nodes[j].word;
               nodes[j].explain = textstream.readLine();
               ui->textEdit->append(nodes[j].word+"          "+nodes[j].explain);
           }

        }


}

void Widget::on_checkButton_clicked()
{
    close();
}



