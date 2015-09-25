#ifndef VEGEDIALOG_H
#define VEGEDIALOG_H

#include<QMessageBox>
#include <QDialog>
#include<QString>

namespace Ui {
class VegeDialog;
}

class VegeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VegeDialog(QWidget *parent = 0);

    ~VegeDialog();
//extern    QString mesVegeOutput;
    QString mesVegeString;
    static QString msgVegeshowString;
private slots:
    void on_payPushButton_clicked();

    void on_refusePushButton_clicked();

    void on_returnPushButton_clicked();

private:
    Ui::VegeDialog *ui;
};

#endif // VEGEDIALOG_H
