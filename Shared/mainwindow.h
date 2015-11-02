#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedMemory>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel *picLabel;
private:
    QSharedMemory *shareMemory;
    void share();
    void get();
};

#endif // MAINWINDOW_H
