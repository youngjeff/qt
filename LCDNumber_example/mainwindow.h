#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void showTime();
private:
    Ui::MainWindow *ui;
    QTimer timerout;
    int Qhour;
    int Qminute;
    int Qsecond;
};

#endif // MAINWINDOW_H
