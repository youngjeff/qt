#ifndef CHANGEWIDGET_H
#define CHANGEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>

class ChangeWidget :public QWidget
{
    Q_OBJECT
public:
    ChangeWidget(QWidget *parent = 0);
    ~ChangeWidget();
    QPushButton *changeButton;
    QPushButton *findButton;
    QLineEdit *findEdit ;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *magerEdit;
    QLineEdit *addressEdit;
private:
    void change();
    void find();
};

#endif // CHANGEWIDGET_H
