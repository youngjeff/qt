#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();
   static QString nameString;
   static QString comboboxString;
private slots:
    void on_loginPushButton_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
