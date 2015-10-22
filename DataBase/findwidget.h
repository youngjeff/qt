#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
class FindWidget :public QWidget
{
    Q_OBJECT
public:
    FindWidget(QWidget *parent =0);
    ~FindWidget();

    QPushButton *findButton;
    QLineEdit *findEdit ;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *magerEdit;
    QLineEdit *addressEdit;
    QLineEdit *idEdit;
private:
    void find();

};

#endif // FINDWIDGET_H
