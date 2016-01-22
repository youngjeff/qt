#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include <QTimer>
#include <QProcess>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);
    ~Add();
    QTimer *timer;
    QString word1,word2,word3,rank,mainsentense,ranksens;
    int ranknumber;
    QProcess *process;

    //void showData();
private slots:
    void on_alspushButton_clicked(); 
    void showData();
    void on_fileButton_clicked();

    void on_dataButton_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
