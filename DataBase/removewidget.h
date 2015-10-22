#ifndef REMOVEWIDGET_H
#define REMOVEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
class RemoveWidget :public QWidget
{
    Q_OBJECT
public:
    RemoveWidget(QWidget *parent =0);
    ~RemoveWidget();
    QPushButton *removeButton;
    QPushButton *findButton;
    QLineEdit *findEdit ;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *magerEdit;
    QLineEdit *addressEdit;
private:
    void remove();
    void find();
};

#endif // REMOVEWIDGET_H
