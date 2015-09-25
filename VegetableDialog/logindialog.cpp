#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}
QString loginDialog::comboboxString;
QString loginDialog::nameString;
loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginPushButton_clicked()
{
//    QString nameString="";
    nameString=ui->nameLineEdit->text();
//    QString comboboxString;
    switch(ui->classComboBox->currentIndex())
    {
    case 0:comboboxString="可爱的客户:";break;
    case 1:comboboxString="尊敬的客户:";break;
    case 2:comboboxString="重要的客户:";break;
    case 3:comboboxString="神圣的客户:";break;
    }
    if(nameString!=NULL&&ui->classComboBox->currentIndex()!=-1)
    {
        accept();
    }
    else{
        QMessageBox::information(this,tr("信息提醒"),tr("你的信息不完整"));
    }
}
