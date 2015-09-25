#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:
    void on_openPushButton_clicked();

    void on_savePushButton_clicked();

private:
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H
