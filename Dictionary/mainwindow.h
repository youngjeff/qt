#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    struct usrList{
        QString usrName;
        QString passWord;
    };
     usrList List[100];

private slots:
    void on_pushButton_2_clicked();

    void on_sizeUpButton_clicked();

    void on_cancerButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
