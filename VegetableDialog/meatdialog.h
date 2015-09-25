#ifndef MEATDIALOG_H
#define MEATDIALOG_H

#include <QDialog>

namespace Ui {
class meatDialog;
}

class meatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit meatDialog(QWidget *parent = 0);
    ~meatDialog();
    QString msgMeatOutPutString;
    static QString msgMeatShowString;
private slots:
    void on_pPushButton_clicked();

    void on_returnPushButton_clicked();

    void on_clearPushButton_clicked();

private:
    Ui::meatDialog *ui;
};

#endif // MEATDIALOG_H
