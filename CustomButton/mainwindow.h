#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
class MainWindow : public QPushButton
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QPushButton *customButton;
protected:
    void mousePressEvent(QMouseEvent *event);//父类的同名函数

private:
    void onButtonCliecked();
};

#endif // MAINWINDOW_H
