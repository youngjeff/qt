#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int number ;
    struct Node{
        QString word;
        QString explain;
    };
     //Node nodes[10000];
    int valuess ;
private slots:
    void on_pushButton_clicked();

    void on_UpButton_clicked();

    void on_DownButton_clicked();

    void on_reviewButton_clicked();

    void on_checkButton_clicked();

   // void on_progressBar_valueChanged(int value);
    //void prograss();


    //void on_progressBar_valueChanged(int value);

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
