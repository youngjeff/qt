#include "specialdialog.h"
#include "ui_specialdialog.h"
#include<QMessageBox>
SpecialDialog::SpecialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecialDialog)
{
    ui->setupUi(this);
}
 QString SpecialDialog::megSpecialShowString;
SpecialDialog::~SpecialDialog()
{
    delete ui;
}

void SpecialDialog::on_payPushButton_clicked()
{
    int kivi,yePork,crawish,legs,oriangs,litter;
    megSpecialShowString=msgSpecialPString;
    if(ui->kiviCheckBox->isChecked()==true)
    {
        kivi=ui->kiviSpinBox->value();
        msgSpecialPString+="猕猴桃:"+QString::number(kivi);
    }
    if(ui->yeporkCheckBox->isChecked()==true)
    {
        yePork=ui->yeporkSpinBox->value();
        msgSpecialPString+="野猪肉："+QString::number(yePork);
    }
    if(ui->crawishCheckBox->isChecked()==true)
    {
        crawish=ui->crawishSpinBox->value();
        msgSpecialPString=="小龙虾："+QString::number(crawish);
    }
    if(ui->legsCheckBox->isChecked()==true)
    {
        legs=ui->legsSpinBox->value();
        msgSpecialPString+="鸡腿："+QString::number(legs);
    }
    if(ui->oriangesCheckBox->isChecked()==true)
       {
        oriangs=ui->oriangesSpinBox->value();
        msgSpecialPString+="水晶橙："+QString::number(oriangs);
    }
    if(ui->littercheckBox->isChecked()==true)
    {
        litter=ui->litterSpinBox->value();
        msgSpecialPString+="小苹果："+QString::number(litter);
    }
   QMessageBox::information(this,tr("信息显示"),msgSpecialPString,QMessageBox::Ok);
   megSpecialShowString=msgSpecialPString;
        msgSpecialPString="";
}

void SpecialDialog::on_returnPushButton_clicked()
{
    close();
}

void SpecialDialog::on_clearPushButton_clicked()
{
    ui->kiviCheckBox->setChecked(false);
    ui->yeporkCheckBox->setChecked(false);
    ui->crawishCheckBox->setChecked(false);
    ui->legsCheckBox->setChecked(false);
    ui->oriangesCheckBox->setChecked(false);
    ui->littercheckBox->setChecked(false);
    ui->crawishSpinBox->clear();
    ui->kiviSpinBox->clear();
    ui->yeporkSpinBox->clear();
    ui->legsSpinBox->clear();
    ui->oriangesSpinBox->clear();
    ui->litterSpinBox->clear();

    msgSpecialPString="";
    megSpecialShowString=msgSpecialPString;
}
