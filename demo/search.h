#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>
namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    QString wordKey;
private slots:
    void on_pushButton_clicked();

    void on_ComBoBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
