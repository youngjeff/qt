#include "paydialog.h"
#include "ui_paydialog.h"

PayDialog::PayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayDialog)
{
    ui->setupUi(this);
}
QString PayDialog::msgOutPutString;
QString PayDialog::shaMessageString;
PayDialog::~PayDialog()
{
    delete ui;
}

void PayDialog::on_watchPushButton_clicked()
{
//        QString msgOutPutString;
        msgOutPutString=loginDialog::comboboxString+loginDialog::nameString+"\n"+VegeDialog::msgVegeshowString+"\n"+SpecialDialog::megSpecialShowString+"\n"+
                meatDialog::msgMeatShowString+"\n"+FruitDialog::msgFruitShowString;
        ui->plainTextEdit->setPlainText(msgOutPutString);
}

void PayDialog::on_savePushButton_clicked()
{
        QString strFileName;
        strFileName = QFileDialog::getSaveFileName(this,tr("保存..."),".",tr("文本文件(*.txt)"));
        if(!strFileName.isEmpty())
        {
            QFile outputFile(strFileName);
            outputFile.open(QFile::WriteOnly);
            QTextStream outTS(&outputFile);
            QTextCodec *outCodec = QTextCodec::codecForName("UTF-8");
            outTS.setCodec(outCodec);
//            outTS<<ui->TxtTextEdit->toPlainText();
            outTS<<ui->plainTextEdit->toPlainText();
            outputFile.flush();
            outputFile.close();

        }

}

void PayDialog::on_shaPushButton_clicked()
{
        QString shaNeedString;
//        QString msgBoxOutputString;
//        QString shaMessageString;
        QByteArray byteArray;
        QByteArray hashByteArray;
        shaNeedString=ui->plainTextEdit->toPlainText();
        byteArray.append(shaNeedString);
        hashByteArray=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha1);
        shaMessageString=hashByteArray.toHex();
        QMessageBox::information(this,tr("加密信息显示"),shaMessageString,QMessageBox::Ok);
}

void PayDialog::on_shaSavePushButton_clicked()
{
    QString strFileName;
    strFileName = QFileDialog::getSaveFileName(this,tr("保存..."),".",tr("文本文件(*.txt)"));
    if(!strFileName.isEmpty())
    {
        QFile outputFile(strFileName);
        outputFile.open(QFile::WriteOnly);
        QTextStream outTS(&outputFile);
        QTextCodec *outCodec = QTextCodec::codecForName("UTF-8");
        outTS.setCodec(outCodec);
        outTS<<shaMessageString;
        outputFile.flush();
        outputFile.close();

    }
}

void PayDialog::on_payPushButton_clicked()
{

    ui->plainTextEdit->clear();
    QMessageBox::information(this,tr("确认信息"),"欢迎下次光临",QMessageBox::Ok);

}

void PayDialog::on_closePushButton_clicked()
{
        close();
}
