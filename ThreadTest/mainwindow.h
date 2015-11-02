#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include "workerthread.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLCDNumber *lcdNumber;
     QTimer *timer;
private:
    void display();
    void showTime();
};

#endif // MAINWINDOW_H
