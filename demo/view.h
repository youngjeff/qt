#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
#include <QStringList>
namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
    void rankComBoBox();
    void informComBoBox();
    QSqlDatabase db;
    QStringList ranks;
    int ranknumber;
    QString mainsenten;
private slots:


    void on_informComBoBox_currentTextChanged(const QString &arg1);

    void on_rankComboBox_currentIndexChanged(int index);

private:
    Ui::View *ui;
};

#endif // VIEW_H
