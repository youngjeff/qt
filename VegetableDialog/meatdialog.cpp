#include "meatdialog.h"
#include "ui_meatdialog.h"
#include <QMessageBox>
meatDialog::meatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meatDialog)
{
    ui->setupUi(this);
}
QString meatDialog::msgMeatShowString;
meatDialog::~meatDialog()
{
    delete ui;
}

void meatDialog::on_pPushButton_clicked()
{
    int pork,mutton,beef,paigu,feirou,chicken,duck,fish;
     msgMeatShowString=msgMeatOutPutString;
    if(ui->porkCheckBox->isChecked()==true)
    {
        pork=ui->porkSpinBox->value();
        msgMeatOutPutString+="猪肉："+QString::number(pork)+"/ 斤";
    }
    if(ui->muttonCheckBox->isChecked()==true)
    {
        mutton=ui->muttonSpinBox->value();
        msgMeatOutPutString+="羊肉："+QString::number(mutton)+"/斤";
    }
    if(ui->beefCheckBox->isChecked()==true)
    {
        beef=ui->beefspinBox->value();
        msgMeatOutPutString+="牛肉："+QString::number(beef)+"/斤";
    }
    if(ui->paiguCheckBox->isChecked()==true)
    {
        paigu=ui->paiguSpinBox->value();
        msgMeatOutPutString+="排骨："+QString::number(paigu)+"/斤";
    }
    if(ui->chickCheckBox->isChecked()==true)
    {
        chicken=ui->chickenSpinBox->value();
        msgMeatOutPutString+="鸡肉:"+QString::number(chicken)+"/斤";
    }
    if(ui->duckCheckBox->isChecked()==true)
    {
        duck=ui->duckSpinBox->value();
        msgMeatOutPutString+="鸭肉："+QString::number(duck)+"/斤";
    }
    if(ui->feirouCheckBox->isChecked()==true)
    {
        feirou=ui->feirouSpinBox->value();
        msgMeatOutPutString+="肥肉："+QString::number(feirou)+"/斤";
    }
    if(ui->fishCheckBox->isChecked()==true)
    {
        fish=ui->fishSpinBox->value();
        msgMeatOutPutString+="鱼肉："+QString::number(fish)+"/斤";
    }
    QMessageBox::information(this,tr("信息显示"),msgMeatOutPutString,QMessageBox::Ok);
    msgMeatShowString=msgMeatOutPutString;
    msgMeatOutPutString="";
}

void meatDialog::on_returnPushButton_clicked()
{
    close();
}

void meatDialog::on_clearPushButton_clicked()
{
    ui->beefCheckBox->setChecked(false);
    ui->chickCheckBox->setChecked(false);
    ui->duckCheckBox->setChecked(false);
    ui->feirouCheckBox->setChecked(false);
    ui->porkCheckBox->setChecked(false);
    ui->paiguCheckBox->setChecked(false);
    ui->muttonCheckBox->setChecked(false);
    ui->fishCheckBox->setChecked(false);
    ui->beefspinBox->clear();
    ui->chickenSpinBox->clear();
    ui->duckSpinBox->clear();
    ui->feirouSpinBox->clear();
    ui->porkSpinBox->clear();
    ui->paiguSpinBox->clear();
    ui->muttonSpinBox->clear();
    ui->fishSpinBox->clear();\

    msgMeatOutPutString="";
    msgMeatShowString=msgMeatOutPutString;
}
