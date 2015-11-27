#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QVariantMap>
#include <QVariantList>
#include <iostream>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <iostream>
#include <QMessageBox>
#include <QMovie>
#include <QUrl>
#include <QNetworkReply>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,600);

    linedit = new QLineEdit(this);
    linedit->setPlaceholderText("which city you want to kown");
    linedit->setStyleSheet("border: 3px solid blue;border-radius:10px");
    //linedit->setGeometry(200,0,300,100);
    button  = new QPushButton(this);

    button->setStyleSheet("background-color:rgb(200,155,100)");
    button->setText("clicked");
    label = new QLabel(this);
    site  = new QLabel;
    pm2   = new QLabel;
    datetime = new QLabel;
    waitlabel = new QLabel;
//    waitlabel->setText("请不要着急，天气小子为您加载数据...");
    waitlabel->setText("                             ");
    label->setText("please input city");
    //label->setGeometry(0,0,200,100);
    site->setText("place");
    pm2->setText("pm2");
    datetime->setText("datetime");
    first  = new QWidget;
    second = new QWidget;
    third  = new QWidget;
    four   = new QWidget;
    stack  = new QStackedWidget;
    stack->addWidget(first);
    stack->addWidget(second);
    stack->addWidget(third);
    stack->addWidget(four);
    stack->setStyleSheet("border: 3px solid green;border-radius:5px");
    textedit = new QTextEdit;
    textedit->setStyleSheet("border: 3px solid red ;border-radius:10px");
    combobox = new QComboBox;
    combobox->setStyleSheet("border: 3px solid blue;border-radius:10px");
    combobox->addItem("今天");
    combobox->addItem("明天");
    combobox->addItem("后天");
    combobox->addItem("大后天");
    QVBoxLayout *vbox = new QVBoxLayout;
    QHBoxLayout *hbox = new QHBoxLayout;
    QHBoxLayout *citybox = new QHBoxLayout;
    QHBoxLayout *strechbox = new QHBoxLayout;

    strechbox->addWidget(waitlabel);

//    strechbox->addWidget(button);
//    strechbox->addStretch(100);

    citybox->addWidget(site);
    citybox->addWidget(pm2);
    citybox->addWidget(datetime);
    hbox->addWidget(label);
    hbox->addWidget(linedit);
    hbox->addWidget(button);
    vbox->addLayout(hbox);
//    vbox->addWidget(button);
    vbox->addLayout(strechbox);
    vbox->addLayout(citybox);
    //    vbox->addWidget(site);
    //    vbox->addWidget(pm2);
    vbox->addWidget(combobox);
    vbox->addWidget(stack);
    vbox->addWidget(textedit);

    manager = new QNetworkAccessManager(this);



    this->setLayout(vbox);

    connect(button,&QPushButton::clicked,this,&Widget::getjson);
    //    connect(combobox,&QComboBox::activated,stack,&QStackedWidget::setCurrentIndex);
    connect(combobox, SIGNAL(activated(int)),
                stack, SLOT(setCurrentIndex(int)));
    showwidget();

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));
    picTimer = new QTimer;
    connect(picTimer,&QTimer::timeout,this,&Widget::showstack);

    picTimer->setInterval(3000);


}

Widget::~Widget()
{

}
void Widget::getjson()
{
    process = new QProcess;
    QString processString = "python untitled-1.py "+ linedit->text();
    process->start(processString);
    //QProcess::execute("./untitled-1.py  北京");
    timer->start(3000);
    waitlabel->setText("请不要着急，天气小子为您加载数据... ... ...");
    picTimer->start();
    pixstackint = -1;
}

void Widget::showData()
{

    waitlabel->setText("                             ");
    QFile file("./weathers");
    if(!file.open(QIODevice::ReadOnly))
        return ;
    QTextStream in(&file);
    QString str = in.readAll();
    //    textedit->setPlainText(str);
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8(),&error);
    QVariantMap result1 = jsonDocument.toVariant().toMap();
    city[0] = result1["date"].toString();
    foreach (QVariant variant1, result1["results"].toList()) {
        QVariantMap result2 = variant1.toMap();
        city[1] = result2["currentCity"].toString();
        city[2] = result2["pm25"].toString();
        site->setText(city[1]);
        pm2->setText("pm25:  "+city[2]);
        datetime->setText(city[0]);
        int i = 0 ;
        foreach (QVariant variant2, result2["index"].toList()) {
            QVariantMap maps = variant2.toMap();
            indexstring[i][0] = maps["title"].toString();
            indexstring[i][1] = maps["zs"].toString();
            indexstring[i][2] = maps["tipt"].toString();
            indexstring[i][3] = maps["des"].toString();
            i++;
        }
        i = 0;
        foreach (QVariant variant3, result2["weather_data"].toList()) {
            QVariantMap mapss = variant3.toMap();
            weatherstring[i][0] = mapss["date"].toString();
            weatherstring[i][1] = mapss["dayPictureUrl"].toString();
            weatherstring[i][2] = mapss["nightPictureUrl"].toString();
            weatherstring[i][3] = mapss["weather"].toString();
            weatherstring[i][4] = mapss["wind"].toString();
            weatherstring[i][5] = mapss["temperature"].toString();
            i++;
        }
    }
    picNumber = 0;
    showTextedit();
    showPic();
    //downPix();
}

void Widget::showTextedit()
{
    QString indexweather;
    for(int i = 0;i< 6; i++)
    {
        for(int j = 0;j< 4; j++)
        {
            indexweather += indexstring[i][j];
        }
        indexweather += "\n";

    }
    textedit->setText(indexweather);
    showinformation();
}
void Widget::showPic()
{
    pixmap[0][0]->load("./pix/1.png");
    pixmap[0][1]->load("./pix/2.png");
    pixmap[1][0]->load("./pix/3.png");
    pixmap[1][1]->load("./pix/4.png");
    pixmap[2][0]->load("./pix/5.png");
    pixmap[2][1]->load("./pix/6.png");
    pixmap[3][0]->load("./pix/7.png");
    pixmap[3][1]->load("./pix/8.png");
    for(int i = 0;i< 4;i++)
    {
        for(int j=0;j<2;j++)
        {
            picLable[i][j]->setPixmap(*pixmap[i][j]);
            picLable[i][j]->setScaledContents(true);
        }
    }

}

void Widget::showwidget()
{
    QVBoxLayout *stackbox[4];
    stackbox[0] = new QVBoxLayout;
    stackbox[1] = new QVBoxLayout;
    stackbox[2] = new QVBoxLayout;
    stackbox[3] = new QVBoxLayout;
    QHBoxLayout *picBox[4];


    /*for(int i = 0; i< 4;i++)
    {
        picBox[i] = new QHBoxLayout;
        picLable[i][0] = new QLabel;
        fileString = pointString + QString::number(j);
        j++;
        //pixmap[i][0] = new QPixmap(fileString);
        picLable[i][0]->setPixmap(pixmap[i][0]);
        picBox[i]->addWidget(picLable[i][0]);
        picLable[i][1] = new QLabel;
        picBox[i]->addWidget(picLable[i][1]);
        fileString = pointString + QString::number(j);
        j++;
        //pixmap[i][1] = new QPixmap(fileString);
        picLable[i][1]->setPixmap(pixmap[i][1]);
        stackbox[i]->addLayout(picBox[i]);
    }*/
    for(int i = 0; i< 4;i++)
        {
            picBox[i] = new QHBoxLayout;
            picLable[i][0] = new QLabel;
            picLable[i][1] = new QLabel;
            pixmap[i][0] = new QPixmap();
            pixmap[i][1] = new QPixmap();
            picBox[i]->addWidget(picLable[i][0]);
            picBox[i]->addWidget(picLable[i][1]);
            stackbox[i]->addLayout(picBox[i]);
        }

    for(int j = 0;j < 4;j++)
    {
        linedits[0][j] = new QLineEdit(first);
        stackbox[0]->addWidget(linedits[0][j]);
    }
    for(int j = 0;j < 4;j++)
    {
        linedits[1][j] = new QLineEdit(second);
        stackbox[1]->addWidget(linedits[1][j]);
    }
    for(int j = 0;j < 4;j++)
    {
        linedits[2][j] = new QLineEdit(third);
         stackbox[2]->addWidget(linedits[2][j]);
    }
    for(int j = 0;j < 4;j++)
    {
        linedits[3][j] = new QLineEdit(four);
         stackbox[3]->addWidget(linedits[3][j]);
    }

    first->setLayout(stackbox[0]);
    second->setLayout(stackbox[1]);
    third->setLayout(stackbox[2]);
    four->setLayout(stackbox[3]);

}
void Widget::showinformation()
{
    linedits[0][0]->setText(weatherstring[0][0]);
    linedits[1][0]->setText(weatherstring[1][0]);
    linedits[2][0]->setText(weatherstring[2][0]);
    linedits[3][0]->setText(weatherstring[3][0]);
    for(int i=0;i<4;i++)
    {
        linedits[i][1]->setText(weatherstring[i][3]);
        linedits[i][2]->setText(weatherstring[i][4]);
        linedits[i][3]->setText(weatherstring[i][5]);
    }

}
void Widget::showstack()
{

    pixstackint = combobox->currentIndex();

    pixstackint++;

    if(pixstackint == 4)
    {
        pixstackint = 0;
    }
    combobox->setCurrentIndex(pixstackint);
    stack->setCurrentIndex(pixstackint);

}

















