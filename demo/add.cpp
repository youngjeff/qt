#include "add.h"
#include "ui_add.h"
#include <QProcess>
#include <QTextStream>
#include <QFile>
#include <QChar>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    timer = new QTimer;
    process = new QProcess;
    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));

}

Add::~Add()
{
    delete ui;
}


void Add::on_alspushButton_clicked()
{

    //QString sentence = ui->inTextEdit->toPlainText();
    //QString processString = "python ala.py "+ '\''+sentence+'\'';
    QString processString = "python ala.py "+ ui->inTextEdit->toPlainText();
    //QString processString = "python ala.py "+ ui->lineEdit->text();
    process->start(processString);
    timer->start(3000);
    ui->label->setText("请稍等，正在努力分析中......");

}
void Add::showData()
{
    QString infor[14]={"体育","教育","财经","社会","娱乐","军事","国内","科技","互联网","房产","国际","女人","汽车","游戏"};

    ui->outTextEdit->clear();
    ui->label->setText("分析结果如下");
    QFile file("./datas");
    if(!file.open(QIODevice::ReadOnly))
        return ;
    QTextStream in(&file);

    word1 = in.readLine();
    word2 = in.readLine();
    word3 = in.readLine();
    rank  = in.readLine();
    int number = rank.mid(1,1).toInt();
    ranknumber = number;
    ranksens = infor[number];
    mainsentense = in.readAll();
    ui->outTextEdit->append("文章的第一个关键词： " + word1 );
    ui->outTextEdit->append("文章的第二个关键词： " + word2 );
    ui->outTextEdit->append("文章的第三个关键词： " + word3 );
    ui->outTextEdit->append("文章的类型属于： "+ infor[number]);
    ui->outTextEdit->append("文章的概要是： " + mainsentense);

    /*if (timer->isActive())
            timer->stop();*/

}

void Add::on_fileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("open file"),".",
                                                   tr("Text Files(*)"));//打开文件的函数

       if(!path.isEmpty())
       {
           QFile file(path);//创建这个文件
           if(!file.open(QIODevice::ReadWrite |QIODevice::Text))
           {
               QMessageBox::warning(this,tr("write file"),tr("cannot open file:\n%1").arg(path));
               return;
           }

            QTextStream in(&file);
//            textedit->setText(in.readAll());
            ui->inTextEdit->setPlainText(in.readAll());
            file.close();
       }//输入文件内容,用的是 textstream的readall函数
       else{
           QMessageBox::warning(this,tr("path"),tr("you did not select any file."));

       }
}

void Add::on_dataButton_clicked()
{
    QString queryString = QString("insert into inform (word1,word2,word3,mainword,mainsenten,allsenten,rank) values ('%1','%2','%3','%4','%5','%6','%7')").arg(word1)
            .arg(word2).arg(word3).arg(ranksens).arg(mainsentense).arg(ui->inTextEdit->toPlainText()).arg(ranknumber);
    QSqlQuery query;
    query.exec(queryString);
    QMessageBox::information(this,"information","success");

    //db.removeDatabase("inform");

}
