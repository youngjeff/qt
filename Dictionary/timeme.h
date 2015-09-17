#ifndef TIMEME_H
#define TIMEME_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class TimeMe;
}

class TimeMe : public QWidget
{
    Q_OBJECT

public:
    explicit TimeMe(QWidget *parent = 0);
    ~TimeMe();
    QTimer *timerMe;
    int countNumber;
private slots:
    void showme();
private:
    Ui::TimeMe *ui;
};

#endif // TIMEME_H
