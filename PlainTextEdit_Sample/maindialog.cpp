#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_openPushButton_clicked()
{
    QString strFileName;
        strFileName = QFileDialog::getOpenFileName(this, tr("打开..."), ".", tr("文本文件 (*.txt)"));
        if(!strFileName.isEmpty())
        {
            if(QFile::exists(strFileName))
            {
                QFile inputFile(strFileName);
                if(inputFile.open(QFile::ReadOnly))
                {
                    QByteArray inputData = inputFile.readAll();
                    ui->TxtPlainTextEdit->setPlainText(QObject::tr(inputData));
                    inputFile.flush();
                    inputFile.close();
                    setWindowTitle("QNotepad");
                }
                else
                {
                    QMessageBox::warning(this, tr("失败"), tr("打开文件失败!"));
                }
            }
            else
            {
                QMessageBox::warning(this, tr("失败"), tr("文件不存在!"));
            }
        }
}

void MainDialog::on_savePushButton_clicked()
{
    QString strFileName;
    strFileName = QFileDialog::getSaveFileName(this, tr("保存..."), ".", tr("文本文件 (*.txt)"));
    if(!strFileName.isEmpty())
    {
        QFile outputFile(strFileName);
        outputFile.open(QFile::WriteOnly);
        QTextStream outTS(&outputFile);
        QTextCodec *outCodec = QTextCodec::codecForName("UTF-8");
        outTS.setCodec(outCodec);
        outTS << ui->TxtPlainTextEdit->toPlainText();
        outputFile.flush();
        outputFile.close();
        setWindowTitle("QNotepad");
    }
    else
    {
        QMessageBox::warning(this, tr("失败"), tr("文件不存在!"));
    }
}
