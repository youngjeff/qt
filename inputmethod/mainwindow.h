// --------------------------------------------------
// Project created by freedomxura 2009-05-27T09:15:17
// The Qt version is Qt 4.5.1
// --------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include <QString>
#include <QtSql>
#include <QList>

#include "../SerialPort/ManageSerialPort.h" //串口

class QWidget;
class QPalette;
class QPixmap;
class QIcon;
class QToolButton;

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    //MainWindow(QWidget *parent = 0,QString s=QString("Hello,Ubuntu!"));
    ~MainWindow();
    QWidget *widget;
    QPalette palette;
    QPixmap pixmap;
    QIcon *icon;
    QToolButton *button;
//-------------------------------------------------------------------
//------------------------------串口部分声明---------------------------
//-------------------------------------------------------------------
public:
   void GetData(QString s)
    {
        senddata=s;
    }
    void SetPort();          //设置串口参数
private slots:
    void slot_send();         //按下 send 则发送数据
    void OpenSerialFail();
private:
    bool openPort();
signals:
    void SerialPortFail();
private:
    ManageSerialPort *serialPort;//调用串口上层类ManageSerialPort指针对象serialPort
    QString senddata;
    QByteArray allDataReceived;
    PortSettings portset;    //结构体
//-------------------------------------------------------------------
//--------------------------以上皆为串口部分---------------------------
//-------------------------------------------------------------------

public slots:   //槽函数声明
    //*************************************************************
    //字母消息
    //*************************************************************
    void accept_A();
    void accept_B();
    void accept_C();
    void accept_D();
    void accept_E();
    void accept_F();
    void accept_G();
    void accept_H();
    void accept_I();
    void accept_J();
    void accept_K();
    void accept_L();
    void accept_M();
    void accept_N();
    void accept_O();
    void accept_P();
    void accept_Q();
    void accept_R();
    void accept_S();
    void accept_T();
    void accept_U();
    void accept_V();
    void accept_W();
    void accept_X();
    void accept_Y();
    void accept_Z();

    //*************************************************************
    //删除，确定，上翻，下翻
    //*************************************************************
    void accept_del();
    void accept_enter();
    void accept_up();
    void accept_down();
    void accept_reset();

    //*************************************************************
    //汉字选择
    //*************************************************************
    void accept_select_1();
    void accept_select_2();
    void accept_select_3();
    void accept_select_4();
    void accept_select_5();
    void accept_select_6();
    void accept_select_7();
    void accept_select_8();
    void accept_select_9();
    void accept_select_10();

    //*************************************************************
    //符号选择
    //*************************************************************
    void accept_select_symbol_1();
    void accept_select_symbol_2();
    void accept_select_symbol_3();
    void accept_select_symbol_4();

    //*************************************************************
    //数据库查询
    //*************************************************************
    int zh_click();

private:
    Ui::MainWindowClass *ui;
};

#endif // MAINWINDOW_H
