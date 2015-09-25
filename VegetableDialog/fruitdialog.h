#ifndef FRUITDIALOG_H
#define FRUITDIALOG_H

#include<QMessageBox>
#include <QDialog>

namespace Ui {
class FruitDialog;
}

class FruitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FruitDialog(QWidget *parent = 0);
    ~FruitDialog();
    QString msgFruitOutPut;
 static   QString msgFruitShowString;
private slots:
    void on_payPushButton_clicked();

    void on_clearPushButton_clicked();

    void on_returnPushButton_clicked();

private:
    Ui::FruitDialog *ui;
};

#endif // FRUITDIALOG_H
