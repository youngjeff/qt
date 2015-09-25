#include "vegetabledialog.h"
#include <QApplication>
#include"logindialog.h"
#include"paydialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vegetableDialog w;
    loginDialog logDlg;
    logDlg.show();
    PayDialog payDlg;
    if(logDlg.exec()==QDialog::Accepted){
    w.show();
    if(w.exec()==QDialog::Accepted)
        payDlg.show();
    }

    return a.exec();
}
