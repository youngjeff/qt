#ifndef VEGETABLEDIALOG_H
#define VEGETABLEDIALOG_H

#include<QMessageBox>
#include <QDialog>
#include "vegedialog.h"
#include "fruitdialog.h"
#include "meatdialog.h"
#include "specialdialog.h"
#include "paydialog.h"
namespace Ui {
class vegetableDialog;
}

class vegetableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit vegetableDialog(QWidget *parent = 0);

    ~vegetableDialog();
//    VegeDialog vege;
    VegeDialog vegeDlg;
    FruitDialog frtDlg;
    meatDialog metDlg;
    SpecialDialog spcDlg;
    PayDialog payDlg;
private slots:
    void on_vegatableButton_clicked();

    void on_fruitButton_clicked();



    void on_fruit1PushButton_clicked();

    void on_fruit1PushButton_2_clicked();

    void on_meatButton_clicked();

    void on_pushButton_clicked();

    void on_specialButton_clicked();

    void on_special1pushButton_clicked();

    void on_peoplePushButton_clicked();

private:
    Ui::vegetableDialog *ui;
};

#endif // VEGETABLEDIALOG_H
