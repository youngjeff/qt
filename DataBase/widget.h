#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *submintButton;
    QPushButton *cancelButton;
    QLabel *usrLab;
    QLabel *passLab;
    QLineEdit *usrEdit;
    QLineEdit *passEdit;
private:
    void connects();
    int subMint();

};

#endif // WIDGET_H
