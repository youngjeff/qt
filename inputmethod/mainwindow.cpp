// --------------------------------------------------
// Project created by freedomxura 2009-05-27T09:15:17
// The Qt version is Qt 4.5.1
// --------------------------------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>

QString key_value;
QString display[200];//这种做法有待提高，
QString text;//短信字符串
int num=0;//存放汉字序号
int i=0;
int j=0;
int k=0;
int index_text=0;//短信字符序号
int del;

QString aaaaaaa="Hello,Baby!";  //测试用,发送数据为aaaaaaa, 之前为senddata

QList<QString> list;


QSqlDatabase db;//声明一个全局变量,db

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    //setWindowOpacity(0.9);

    ui->setupUi(this);
    palette.setBrush(QPalette::Base, QBrush(QPixmap("freedom.png")));
    ui->listView->setPalette(palette);









    //-------------------------------------------------------------------
    //------------------------------以下为串口部分-------------------------
    //-------------------------------------------------------------------
    ui->setupUi(this);
    serialPort = new ManageSerialPort();
    senddata="Hello,Baby!";
    SetPort();
    connect(ui->pushButton_Send,SIGNAL(clicked()),this,SLOT(slot_send()));
    connect(this,SIGNAL(SerialPortFail()),this,SLOT(OpenSerialFail()));
    //-------------------------------------------------------------------
    //------------------------------以上为串口部分声明---------------------
    //-------------------------------------------------------------------











    //************************************************************************
    //字母按键按下信号与窗体的关联
    //************************************************************************
    connect(ui->pushButton_A,SIGNAL(clicked()),this,SLOT(accept_A()));
    connect(ui->pushButton_B,SIGNAL(clicked()),this,SLOT(accept_B()));
    connect(ui->pushButton_C,SIGNAL(clicked()),this,SLOT(accept_C()));
    connect(ui->pushButton_D,SIGNAL(clicked()),this,SLOT(accept_D()));
    connect(ui->pushButton_E,SIGNAL(clicked()),this,SLOT(accept_E()));
    connect(ui->pushButton_F,SIGNAL(clicked()),this,SLOT(accept_F()));
    connect(ui->pushButton_G,SIGNAL(clicked()),this,SLOT(accept_G()));
    connect(ui->pushButton_H,SIGNAL(clicked()),this,SLOT(accept_H()));
    connect(ui->pushButton_I,SIGNAL(clicked()),this,SLOT(accept_I()));
    connect(ui->pushButton_J,SIGNAL(clicked()),this,SLOT(accept_J()));
    connect(ui->pushButton_K,SIGNAL(clicked()),this,SLOT(accept_K()));
    connect(ui->pushButton_L,SIGNAL(clicked()),this,SLOT(accept_L()));
    connect(ui->pushButton_M,SIGNAL(clicked()),this,SLOT(accept_M()));
    connect(ui->pushButton_N,SIGNAL(clicked()),this,SLOT(accept_N()));
    connect(ui->pushButton_O,SIGNAL(clicked()),this,SLOT(accept_O()));
    connect(ui->pushButton_P,SIGNAL(clicked()),this,SLOT(accept_P()));
    connect(ui->pushButton_Q,SIGNAL(clicked()),this,SLOT(accept_Q()));
    connect(ui->pushButton_R,SIGNAL(clicked()),this,SLOT(accept_R()));
    connect(ui->pushButton_S,SIGNAL(clicked()),this,SLOT(accept_S()));
    connect(ui->pushButton_T,SIGNAL(clicked()),this,SLOT(accept_T()));
    connect(ui->pushButton_U,SIGNAL(clicked()),this,SLOT(accept_U()));
    connect(ui->pushButton_V,SIGNAL(clicked()),this,SLOT(accept_V()));
    connect(ui->pushButton_W,SIGNAL(clicked()),this,SLOT(accept_W()));
    connect(ui->pushButton_X,SIGNAL(clicked()),this,SLOT(accept_X()));
    connect(ui->pushButton_Y,SIGNAL(clicked()),this,SLOT(accept_Y()));
    connect(ui->pushButton_Z,SIGNAL(clicked()),this,SLOT(accept_Z()));

    connect(ui->pushButton_Reset,SIGNAL(clicked()),this,SLOT(accept_reset()));
    connect(ui->pushButton_Enter,SIGNAL(clicked()),this,SLOT(accept_enter()));
    connect(ui->pushButton_Del,SIGNAL(clicked()),this,SLOT(accept_del()));
    connect(ui->pushButton_Up,SIGNAL(clicked()),this,SLOT(accept_up()));
    connect(ui->pushButton_Down,SIGNAL(clicked()),this,SLOT(accept_down()));


    //***************************************************************************
    //汉字选择信号与槽的关联
    //***************************************************************************
    connect(ui->pushButton_Dis_1,SIGNAL(clicked()),this,SLOT(accept_select_1()));
    connect(ui->pushButton_Dis_2,SIGNAL(clicked()),this,SLOT(accept_select_2()));
    connect(ui->pushButton_Dis_3,SIGNAL(clicked()),this,SLOT(accept_select_3()));
    connect(ui->pushButton_Dis_4,SIGNAL(clicked()),this,SLOT(accept_select_4()));
    connect(ui->pushButton_Dis_5,SIGNAL(clicked()),this,SLOT(accept_select_5()));
    connect(ui->pushButton_Dis_6,SIGNAL(clicked()),this,SLOT(accept_select_6()));
    connect(ui->pushButton_Dis_7,SIGNAL(clicked()),this,SLOT(accept_select_7()));
    connect(ui->pushButton_Dis_8,SIGNAL(clicked()),this,SLOT(accept_select_8()));
    connect(ui->pushButton_Dis_9,SIGNAL(clicked()),this,SLOT(accept_select_9()));
    connect(ui->pushButton_Dis_10,SIGNAL(clicked()),this,SLOT(accept_select_10()));

    //***************************************************************************
    //符号选择信号与槽的关联
    //***************************************************************************
    connect(ui->pushButton_Symbol_1,SIGNAL(clicked()),this,SLOT(accept_select_symbol_1()));
    connect(ui->pushButton_Symbol_2,SIGNAL(clicked()),this,SLOT(accept_select_symbol_2()));
    connect(ui->pushButton_Symbol_3,SIGNAL(clicked()),this,SLOT(accept_select_symbol_3()));
    connect(ui->pushButton_Symbol_4,SIGNAL(clicked()),this,SLOT(accept_select_symbol_4()));


}

void MainWindow::accept_A()
{
    //key_value="a";
   key_value.append("a");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_B()
{
    //key_value="a";
   key_value.append("b");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_C()
{
    //key_value="a";
   key_value.append("c");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_D()
{
    //key_value="a";
   key_value.append("d");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_E()
{
    //key_value="a";
   key_value.append("e");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_F()
{
    //key_value="a";
   key_value.append("f");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_G()
{
    //key_value="a";
   key_value.append("g");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_H()
{
    //key_value="a";
   key_value.append("h");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_I()
{
    //key_value="a";
   key_value.append("i");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_J()
{
    //key_value="a";
   key_value.append("j");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_K()
{
    //key_value="a";
   key_value.append("k");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_L()
{
    //key_value="a";
   key_value.append("l");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_M()
{
    //key_value="a";
   key_value.append("m");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_N()
{
    //key_value="a";
   key_value.append("n");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_O()
{
    //key_value="a";
   key_value.append("o");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_P()
{
    //key_value="a";
   key_value.append("p");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_Q()
{
    //key_value="a";
   key_value.append("q");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_R()
{
    //key_value="a";
   key_value.append("r");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_S()
{
    //key_value="a";
   key_value.append("s");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_T()
{
    //key_value="a";
   key_value.append("t");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_U()
{
    //key_value="a";
   key_value.append("u");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_V()
{
    //key_value="a";
   key_value.append("v");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_W()
{
    //key_value="a";
   key_value.append("w");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_X()
{
    //key_value="a";
   key_value.append("x");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_Y()
{
    //key_value="a";
   key_value.append("y");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_Z()
{
    //key_value="a";
   key_value.append("z");
   ui->lineEdit->setText(key_value);

}

void MainWindow::accept_reset()
{
    key_value="";
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    //display[200]="";
    num=0;
    i=0;
    j=0;
    k=0;
    ui->pushButton_Dis_1->setText("");
    ui->pushButton_Dis_2->setText("");
    ui->pushButton_Dis_3->setText("");
    ui->pushButton_Dis_4->setText("");
    ui->pushButton_Dis_5->setText("");
    ui->pushButton_Dis_6->setText("");
    ui->pushButton_Dis_7->setText("");
    ui->pushButton_Dis_8->setText("");
    ui->pushButton_Dis_9->setText("");
    ui->pushButton_Dis_10->setText("");
}

void MainWindow::accept_del()
{
    text.clear();
    list.removeAt(index_text-del);
    del++;
    qDebug()<<list;
    qDebug()<<"index_text="<<index_text<<"del="<<del;
    int abc;
    for(abc=0;abc<index_text-del+1;abc++)
    {
        text.append(list.at(abc));
    }
    qDebug()<<text;
    ui->textEdit->setText(text);

    qDebug()<<"***********************";
    qDebug()<<list;
}

void MainWindow::accept_enter()
{
    zh_click();
    ui->pushButton_Dis_1->setText(display[0]);
    ui->pushButton_Dis_2->setText(display[1]);
    ui->pushButton_Dis_3->setText(display[2]);
    ui->pushButton_Dis_4->setText(display[3]);
    ui->pushButton_Dis_5->setText(display[4]);
    ui->pushButton_Dis_6->setText(display[5]);
    ui->pushButton_Dis_7->setText(display[6]);
    ui->pushButton_Dis_8->setText(display[7]);
    ui->pushButton_Dis_9->setText(display[8]);
    ui->pushButton_Dis_10->setText(display[9]);
}


void MainWindow::accept_up()
{
    j++;
    ui->pushButton_Dis_1->setText(display[10*j-10*k]);
    ui->pushButton_Dis_2->setText(display[10*j-10*k+1]);
    ui->pushButton_Dis_3->setText(display[10*j-10*k+2]);
    ui->pushButton_Dis_4->setText(display[10*j-10*k+3]);
    ui->pushButton_Dis_5->setText(display[10*j-10*k+4]);
    ui->pushButton_Dis_6->setText(display[10*j-10*k+5]);
    ui->pushButton_Dis_7->setText(display[10*j-10*k+6]);
    ui->pushButton_Dis_8->setText(display[10*j-10*k+7]);
    ui->pushButton_Dis_9->setText(display[10*j-10*k+8]);
    ui->pushButton_Dis_10->setText(display[10*j-10*k+9]);
}

void MainWindow::accept_down()
{
    k++;
    ui->pushButton_Dis_1->setText(display[10*j-10*k]);
    ui->pushButton_Dis_2->setText(display[10*j-10*k+1]);
    ui->pushButton_Dis_3->setText(display[10*j-10*k+2]);
    ui->pushButton_Dis_4->setText(display[10*j-10*k+3]);
    ui->pushButton_Dis_5->setText(display[10*j-10*k+4]);
    ui->pushButton_Dis_6->setText(display[10*j-10*k+5]);
    ui->pushButton_Dis_7->setText(display[10*j-10*k+6]);
    ui->pushButton_Dis_8->setText(display[10*j-10*k+7]);
    ui->pushButton_Dis_9->setText(display[10*j-10*k+8]);
    ui->pushButton_Dis_10->setText(display[10*j-10*k+9]);
    qDebug ()<<"j="<<j<<",k="<<k;
    if(j<=k)
    {

     ui->pushButton_Dis_1->setText(display[0]);
     ui->pushButton_Dis_2->setText(display[1]);
     ui->pushButton_Dis_3->setText(display[2]);
     ui->pushButton_Dis_4->setText(display[3]);
     ui->pushButton_Dis_5->setText(display[4]);
     ui->pushButton_Dis_6->setText(display[5]);
     ui->pushButton_Dis_7->setText(display[6]);
     ui->pushButton_Dis_8->setText(display[7]);
     ui->pushButton_Dis_9->setText(display[8]);
     ui->pushButton_Dis_10->setText(display[9]);

        qDebug ()<<num;
        k=0;
    }

}

void MainWindow::accept_select_1()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_2()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+1]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+1]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_3()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+2]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+2]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_4()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+3]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+3]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_5()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+4]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+4]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_6()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+5]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+5]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_7()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+6]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+6]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_8()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+7]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+7]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_9()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+8]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+8]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_10()
{
    //text = display[10*j-10*k+1];
    text.append(display[10*j-10*k+9]);
    ui->textEdit->setText(text);
    list.append(display[10*j-10*k+9]);
    index_text++;

    qDebug() << list;
}

void MainWindow::accept_select_symbol_1()
{    
     text.append(",");
     ui->textEdit->setText(text);
     list.append(",");
     index_text++;
     qDebug() << list;
}

void MainWindow::accept_select_symbol_2()
{
     text.append(".");
     ui->textEdit->setText(text);
     list.append(".");
     index_text++;
     qDebug() << list;
}

void MainWindow::accept_select_symbol_3()
{
     text.append("?");
     ui->textEdit->setText(text);
     list.append("?");
     index_text++;
     qDebug() << list;
}

void MainWindow::accept_select_symbol_4()
{
     text.append("!");
     ui->textEdit->setText(text);
     list.append("!");
     index_text++;
     qDebug() << list;
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

//数据库测试函数
int MainWindow::zh_click()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("zhpy_table.db");

    if ( !db.open())
    {
  QMessageBox::critical(NULL, QObject::tr("无法打开数据库\n"), QObject::tr("退出清按Cancel键"),QMessageBox::Cancel,QMessageBox::NoButton);
  return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM zhcn WHERE py=:pinyin");
    query.bindValue(":pinyin",key_value);
    if(query.exec())
                {
                        qDebug()<<QObject::tr("query success!\n");
                }
    else
        qDebug()<<QObject::tr("query failed!\n");
    QString tmp;
    while(query.next())
    {
        tmp = query.value(2).toString();
        display[num]=tmp;
        num++;//总的汉字个数
        qDebug() << tmp;
    }
}


//-------------------------------------------------------------------
//------------------------------以下为串口部分-------------------------
//-------------------------------------------------------------------
bool MainWindow::openPort()
{

    if (serialPort->isOpen())           //如果串口是开得则关闭
        serialPort->close();
    //设置串口参数
    serialPort->setPort(QString("/dev/ttyS0")); //开启第一个串口设备
    serialPort->setBaudRate(portset.BaudRate); //设置波特率
    serialPort->setDataBits(portset.DataBits); //设置数据位的位数
    serialPort->setParity(portset.Parity); //校验类型
    serialPort->setStopBits(portset.StopBits); //停止位位数
    serialPort->setFlowControl(portset.FlowControl); //控制流
    serialPort->setTimeout(0, 10);
    serialPort->enableSending();
    serialPort->enableReceiving();
    serialPort->open();  //开串口
    if (serialPort->isOpen())
        return true;
    else
        return false;
    serialPort->receiveData();        //新建接受线程
}
void MainWindow::SetPort()            //设置串口
{
    portset.BaudRate=BAUD9600;
    portset.DataBits=DATA_8;
    portset.Parity=PAR_NONE;
    portset.FlowControl=FLOW_OFF;
    portset.StopBits=STOP_1;
    portset.Timeout_Millisec=10;
    portset.Timeout_Sec=0;
}
void MainWindow::slot_send()
{
        if (openPort())
    {
        //senddata += "\x0D";      //加结束标志
        //senddata += "\x0A";
        //QByteArray temp(senddata.toUtf8()); //带编码
         QByteArray temp(aaaaaaa.toUtf8()); //带编码
        serialPort->sendData(temp);
        //serialPort->sendData("I Love you");
        qDebug()<<" SendSuccess!baby!";
    }
       else emit SerialPortFail();
   }
void MainWindow::OpenSerialFail()    //    若串口打开失败则弹出警告
{
    QErrorMessage *errmsg=new QErrorMessage(this);
    errmsg->showMessage(QString("Serial port open failed!Please try again"));
}
//-------------------------------------------------------------------
//------------------------------以上为串口部分声明---------------------
//-------------------------------------------------------------------
