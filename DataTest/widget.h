#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QTextEdit>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *dbButton;
    QPushButton *selectButton;
    QTextEdit *textedit;
    void connects();
    void selects();
};

#endif // WIDGET_H

