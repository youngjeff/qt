#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    int sum;
    int temp;
    int result;
    ~Dialog();
public slots:
    void b1clicked();
    void b2clicked();
    void b3clicked();
    void b4clicked();
    void b5clicked();
    void b6clicked();
    void b7clicked();
    void b8clicked();
    void b9clicked();
    void b0clicked();
    void b00clicked();
    void add();
    void sub();
    void multi();
    void div();
    void equls();
    void quit();
    void clear();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
