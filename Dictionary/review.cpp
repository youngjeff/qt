#include "review.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include "widget.h"
#include <QMessageBox>
Review::Review()
{
    this->resize(600,600);

    QVBoxLayout *vbox = new QVBoxLayout;
    explainedit = new QTextEdit;
    explainedit->setStyleSheet("  background: lightblue;");
    inPutedit   = new QTextEdit;
    inPutedit->setStyleSheet(" background: lightblue;");
    vbox->addWidget(explainedit);
    vbox->addWidget(inPutedit);

    this->setLayout(vbox);
    QHBoxLayout *hbox = new QHBoxLayout;
    startButton = new QPushButton("start");
//    startButton->set
    startButton->setStyleSheet("  color: rgb(0,88,152); background-color: rgba(87%,80%,9%,40%)");

    checkButton = new QPushButton("check");
    checkButton->setStyleSheet("color: rgb(0,88,152); background-color: rgba(77%,80%,9%,50%)");
    LookButton  = new QPushButton("查看答案");
    LookButton->setStyleSheet("color: rgb(0,88,152); background-color: rgba(67%,80%,9%,60%)");
    returnButton = new QPushButton("return");
    returnButton->setStyleSheet("color: rgb(0,88,152); background-color: rgba(57%,80%,9%,70%)");

    hbox->addWidget(startButton);
    hbox->addWidget(checkButton);
    hbox->addWidget(LookButton);
    hbox->addWidget(returnButton);
    vbox->addLayout(hbox,20);
//    QHBoxLayout *allbox = new QHBoxLayout;
//    allbox->addLayout(vbox);
//    allbox->addLayout(hbox);
    this->setLayout(vbox);

    connect(startButton,&QPushButton::clicked,this,&Review::onStart);
    connect(checkButton,&QPushButton::clicked,this,&Review::onCheck);
    connect(LookButton,&QPushButton::clicked,this,&Review::onLook);
    connect(returnButton,&QPushButton::clicked,this,&Review::onReturn);
    number = 0;
}
void Review::onStart()
{
    for(int i = 0 ;i < 15; i++)
    {
//        explainedit->setPlainText(Widget::nodess[i].explain);
       words[i].words = Widget::nodess[i].word;
       words[i].explain = Widget::nodess[i].explain;
    }
    explainedit->clear();
    explainedit->setPlainText(words[number].explain);
}
void Review::onCheck()
{
    QString inPutString;
    int temp = 0;
    inPutString = inPutedit->toPlainText();
    if(inPutString == words[number].words)
    {
        QMessageBox::information(this,"show","yes",QMessageBox::Ok);
        temp = 1;
        inPutedit->clear();
    }
    else
    {
        QMessageBox::information(this,"show","no",QMessageBox::Ok);
        temp = 0;
        inPutedit->clear();
    }
    if(temp == 1)
    {
        number++;
        explainedit->clear();
        explainedit->setPlainText(words[number].explain);
    }

}
void Review::onLook()
{
    explainedit->clear();
    explainedit->setPlainText(words[number].words);
}
void Review::onReturn()
{
    this->close();
    Widget *widget = new Widget;
    widget->show();
}
