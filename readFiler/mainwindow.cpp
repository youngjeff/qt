#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include <QTextBlock>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_push1Button_clicked()
{
    QString strFileName;
    strFileName = QFileDialog::getOpenFileName(this, tr("打开..."), ".", tr("文本文件 (*.txt)"));
    if(!strFileName.isEmpty())
    {
        if(QFile::exists(strFileName))
        {
            QFile inputFile(strFileName);
            if(inputFile.open(QFile::ReadOnly))
            {
                QByteArray inputData = inputFile.readAll();
                ui->plain1TextEdit->setPlainText(QObject::tr(inputData));
                inputFile.flush();
                inputFile.close();
                setWindowTitle("QNotepad");
            }
            else
            {
                QMessageBox::warning(this, tr("失败"), tr("打开文件失败!"));
            }
        }
        else
        {
            QMessageBox::warning(this, tr("失败"), tr("文件不存在!"));
        }
    }
    if(!strFileName.isEmpty())
    {
        int i=1;
        int lines=ui->plain1TextEdit->document()->lineCount();
        //qDebug("%d",lines);

        while(i<=lines)
        {
            message1[i]=ui->plain1TextEdit->document()->findBlockByLineNumber(i-1).text();
            i++;
        }
        //findBlockByLineNumber
        //qDebug("%s",message1[1]);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QString strFileName;
    strFileName = QFileDialog::getOpenFileName(this, tr("打开..."), ".", tr("文本文件 (*.txt)"));
    if(!strFileName.isEmpty())
    {
        if(QFile::exists(strFileName))
        {
            QFile inputFile(strFileName);
            if(inputFile.open(QFile::ReadOnly))
            {
                QByteArray inputData = inputFile.readAll();
                ui->plain2TextEdit->setPlainText(QObject::tr(inputData));
                inputFile.flush();
                inputFile.close();
                setWindowTitle("QNotepad");
            }
            else
            {
                QMessageBox::warning(this, tr("失败"), tr("打开文件失败!"));
            }
        }
        else
        {
            QMessageBox::warning(this, tr("失败"), tr("文件不存在!"));
        }
    }

    if(!strFileName.isEmpty())
    {
        int i=1;
        int lines=ui->plain1TextEdit->document()->lineCount();
        while(i<=lines)
        {
            message2[i]=ui->plain2TextEdit->document()->findBlockByLineNumber(i-1).text();
            i++;
        }
        //QMessageBox::information(this,"",message2[1]);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    int i=1,j=1;
    int temp=0;
    int count=0;
    int line1=ui->plain1TextEdit->document()->lineCount();
    //int line2=ui->plain2TextEdit->document()->lineCount();
    /*for(i=1;i<=line1;i++)
    {
        for(j=1;j<=line2;j++)
        {
            if(message1[i]==message2[j])
                message3+=message1[i]+'\n';
            temp=1;
        }
    }
    if(temp==0)
        ui->plain3TextEdit->setPlainText("sorry ,no answer");
    ui->plain3TextEdit->setPlainText(message3);*/
    //qDebug("%d",line1);
   // qDebug("%s",message1);

    for(i=1;i<line1;i++)
        {
           int length=message1[i].length();
           //qDebug("%d",length);
           for(int j=0;j<=length;j++)
           {
               if(message1[i][j]=='1'){
                   //message3[i]=(j+1)/2+1;
                   qDebug("%d",(j+1)/2+1);
                   count++;
                   //message4+=QString::number(message3[i])+'\n';
                   break;
                   }
           }
        }
        qDebug("%d",count);
        //ui->plain3TextEdit->setPlainText(message4);

}
