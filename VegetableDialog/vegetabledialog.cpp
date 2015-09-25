#include "vegetabledialog.h"
#include "ui_vegetabledialog.h"

vegetableDialog::vegetableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vegetableDialog)
{
    ui->setupUi(this);
}

vegetableDialog::~vegetableDialog()
{
    delete ui;
}

void  vegetableDialog::on_vegatableButton_clicked()
{


    vegeDlg.show();

}

void vegetableDialog::on_fruitButton_clicked()
{
    frtDlg.show();
}


void vegetableDialog::on_fruit1PushButton_clicked()
{
    vegeDlg.show();
}

void vegetableDialog::on_fruit1PushButton_2_clicked()
{
    frtDlg.show();
}

void vegetableDialog::on_meatButton_clicked()
{
    metDlg.show();
}

void vegetableDialog::on_pushButton_clicked()
{
    metDlg.show();
}

void vegetableDialog::on_specialButton_clicked()
{
    spcDlg.show();
}

void vegetableDialog::on_special1pushButton_clicked()
{
    spcDlg.show();
}

void vegetableDialog::on_peoplePushButton_clicked()
{
    accept();
}
