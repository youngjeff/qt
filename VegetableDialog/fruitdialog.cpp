#include "fruitdialog.h"
#include "ui_fruitdialog.h"
#include<QMessageBox>
FruitDialog::FruitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FruitDialog)
{
    ui->setupUi(this);
}
 QString FruitDialog::msgFruitShowString;
FruitDialog::~FruitDialog()
{
    delete ui;
}

void FruitDialog::on_payPushButton_clicked()
{
//    QString apple,pear,peach,watermelon,mugua,banala;
    int appleValue,pearValue,peachValue,waterValue,muguaValue,banalaValue;
    msgFruitShowString=msgFruitOutPut;
    if(ui->appleCheckBox->isChecked()==true)
    {
        appleValue=ui->appleSpinBox->value();
        msgFruitOutPut+="苹果："+QString::number(appleValue)+"/斤";
    }
    if(ui->pearCheckBox->isChecked()==true)
    {
        pearValue=ui->pearSpinBox->value();
        msgFruitOutPut+="梨子:"+QString::number(pearValue)+"/斤";
    }
    if(ui->banalaCheckBox->isChecked()==true)
    {
        banalaValue=ui->bananaSpinBox->value();
        msgFruitOutPut+="香蕉"+QString::number(banalaValue)+"/斤";
    }
    if(ui->waterlemonCheckBox->isChecked()==true)
    {
        waterValue=ui->waterSpinBox->value();
        msgFruitOutPut+="西瓜"+QString::number(waterValue)+"/斤";
    }
    if(ui->muguaCheckBox->isChecked()==true)
    {
        muguaValue=ui->muguaSpinBox->value();
        msgFruitOutPut+="木瓜"+QString::number(muguaValue)+"/斤";
    }
    if(ui->peachCheckBox->isChecked()==true)
    {
        peachValue=ui->peachSpinBox->value();
        msgFruitOutPut+="桃子"+QString::number(peachValue)+"/斤";
    }
    QMessageBox::information(this,tr("信息显示"),msgFruitOutPut);
    msgFruitShowString=msgFruitOutPut;
    msgFruitOutPut="";

}

void FruitDialog::on_clearPushButton_clicked()
{
    ui->appleCheckBox->setChecked(false);
    ui->banalaCheckBox->setChecked(false);
    ui->pearCheckBox->setChecked(false);
    ui->peachCheckBox->setChecked(false);
    ui->waterlemonCheckBox->setChecked(false);
    ui->muguaCheckBox->setChecked(false);
    ui->appleSpinBox->clear();
    ui->bananaSpinBox->clear();
    ui->pearSpinBox->clear();
    ui->peachSpinBox->clear();
    ui->waterSpinBox->clear();
    ui->muguaSpinBox->clear();
    msgFruitShowString=msgFruitOutPut;
    msgFruitOutPut="";
}

void FruitDialog::on_returnPushButton_clicked()
{
    close();
}
