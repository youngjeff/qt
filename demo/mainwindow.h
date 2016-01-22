#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <add.h>
#include <view.h>
#include <search.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;
    void showText();
private slots:
    void on_addButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
