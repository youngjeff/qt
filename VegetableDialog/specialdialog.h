#ifndef SPECIALDIALOG_H
#define SPECIALDIALOG_H

#include<QMessageBox>
#include <QDialog>
namespace Ui {
class SpecialDialog;
}

class SpecialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpecialDialog(QWidget *parent = 0);
    ~SpecialDialog();
    QString msgSpecialPString;
    static QString megSpecialShowString;
private slots:
    void on_payPushButton_clicked();

    void on_returnPushButton_clicked();

    void on_clearPushButton_clicked();

private:
    Ui::SpecialDialog *ui;
};

#endif // SPECIALDIALOG_H
