#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListView>
#include <QStringList>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QStringListModel>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
        QListView *view;
        QStringListModel *model;
        QSortFilterProxyModel *modelProxy;
        QComboBox *syntaxBox;
//        QStringListModel *syntaxBox;
private slots:
        void filterChanged(const QString &text);
};

#endif // WIDGET_H
