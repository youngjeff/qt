#ifndef ADDWIGDET_H
#define ADDWIGDET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
class AddWigdet :public QWidget
{
    Q_OBJECT
public:
    AddWigdet(QWidget *parent = 0);
    ~AddWigdet();
    QPushButton *addButton;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *magerEdit;
    QComboBox *addressBox;
private:
    int addEvent();
};

#endif // ADDWIGDET_H
