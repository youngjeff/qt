#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);//防止隐式转换
    ~MainWindow();
    void open();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
