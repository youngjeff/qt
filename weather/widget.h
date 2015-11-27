#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDevice>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QStackedWidget>
#include <QComboBox>
#include <QProcess>
#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMovie>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *button;
    QLineEdit *linedit;
    QTextEdit *textedit;
    QLabel *label;
    QLabel *site;
    QLabel *pm2;
    QLabel *datetime;
    QLabel *waitlabel;
    QStackedWidget *stack;
    QWidget *first;
    QWidget *second;
    QWidget *third;
    QWidget *four;
    QComboBox *combobox;
    QLineEdit *linedits[4][4];
    QLabel *picLable[4][2];
     QPixmap *pixmap[4][2];
     QMovie  *movie[4][2];
    //QPixmap *pixmap[4][2];
    QTimer *timer;
    QTimer *picTimer;
//    void showData();
    QProcess *process;
    QNetworkAccessManager *manager;
    int pixstackint;
    bool is_start;
    void getjson();
    void showTextedit();
    void showwidget();
    void showinformation();
    void showPic();
    int picNumber;
    void downPix();
    void showstack();
public slots:
    void showData();

private:
    QString city[3];
    QString indexstring[6][4];
    QString weatherstring[4][6];
};






#endif // WIDGET_H
