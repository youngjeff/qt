#include "vegedialog.h"
#include "ui_vegedialog.h"
#include<QMessageBox>
VegeDialog::VegeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VegeDialog)
{
    ui->setupUi(this);
}

QString VegeDialog::msgVegeshowString="";
VegeDialog::~VegeDialog()
{
    delete ui;
}

void VegeDialog::on_payPushButton_clicked()
{
    QString qincai,huluobo,baicai,qingcai,xihongshi,kugua;
    int qincaiValue,huluoboValue,baicaiValue,qingcaiValue,tomatoValue,kuguaValue;
    msgVegeshowString=mesVegeString;
//    QString mesVegeString;
    if(ui->qincaiCheckBox->isChecked()==true)
    {
        qincai="芹菜：";
        qincaiValue=ui->qincaiSpinBox->value();

    }
    else
    {
        qincai="";
        qincaiValue=0;


    }
    if(ui->carrotCheckBox->isChecked()==true)
    {
        huluobo="胡萝卜：";
        huluoboValue=ui->carrotSpinBox->value();
    }
    else{
        huluobo="";
        huluoboValue=0;

    }

    if(ui->baicaicarrotCheckBox->isChecked()==true)
    {
        baicai="白菜";
       baicaiValue=ui->baicaiSpinBox->value();

    }
    else{
        baicai="";
        baicaiValue=0;

    }
    if(ui->qingcaiCheckBox->isChecked()==true)
    {
        qingcai="青菜";
        qingcaiValue=ui->qingcaiSpinBox->value();

    }
    else{
        qingcai="";
        qingcaiValue=0;

    }

    if(ui->tomatoCheckBox->isChecked()==true)
    {
        xihongshi+="西红柿";
        tomatoValue=ui->tomatoSpinBox->value();

    }
    else{
        xihongshi="";
        tomatoValue=0;

    }

    if(ui->kuguaCheckBox->isChecked()==true)
    {
        kugua+="苦瓜";
        kuguaValue=ui->kuguaSpinBox->value();
        mesVegeString+=kugua+QString::number(kuguaValue)+" 斤";
    }
    else{
        kugua="";
        kuguaValue=0;

    }
    if(qincaiValue!=0){
     mesVegeString+=qincai+QString::number(qincaiValue)+" 斤";}
    if(huluoboValue!=0){
     mesVegeString+=huluobo+QString::number(huluoboValue)+" 斤";}
    if(baicaiValue!=0){
     mesVegeString+=baicai+QString::number(baicaiValue)+" 斤";}
    if(qingcaiValue!=0){
     mesVegeString+=qingcai+QString::number(qingcaiValue)+" 斤";}
    if(tomatoValue!=0){
     mesVegeString+=xihongshi+QString::number(tomatoValue)+" 斤";}
    QMessageBox::information(this,tr("信息"),mesVegeString);
    msgVegeshowString=mesVegeString;
    mesVegeString="";
}

void VegeDialog::on_refusePushButton_clicked()
{
    ui->baicaicarrotCheckBox->setChecked(false);
    ui->carrotCheckBox->setCheckable(false);
    ui->kuguaCheckBox->setChecked(false);
    ui->tomatoCheckBox->setChecked(false);
    ui->qingcaiCheckBox->setChecked(false);
    ui->qincaiCheckBox->setChecked(false);
    ui->baicaiSpinBox->clear();
    ui->carrotSpinBox->clear();
    ui->kuguaSpinBox->clear();
    ui->tomatoSpinBox->clear();
    ui->qingcaiSpinBox->clear();
    ui->qincaiSpinBox->clear();
    mesVegeString="";
    msgVegeshowString=mesVegeString;
}

void VegeDialog::on_returnPushButton_clicked()
{
   close();

}
