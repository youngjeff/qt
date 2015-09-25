#ifndef PAYDIALOG_H
#define PAYDIALOG_H

#include<QMessageBox>
#include <QDialog>
#include "vegedialog.h"
#include "fruitdialog.h"
#include "meatdialog.h"
#include "specialdialog.h"
#include "logindialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QMessageBox>
namespace Ui {
class PayDialog;
}

class PayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PayDialog(QWidget *parent = 0);
    ~PayDialog();
    static QString msgOutPutString;
    static QString shaMessageString;
private slots:
    void on_watchPushButton_clicked();

    void on_savePushButton_clicked();

    void on_shaPushButton_clicked();

    void on_shaSavePushButton_clicked();

    void on_payPushButton_clicked();

    void on_closePushButton_clicked();

private:
    Ui::PayDialog *ui;
};

#endif // PAYDIALOG_H
