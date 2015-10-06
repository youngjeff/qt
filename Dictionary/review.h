#ifndef REVIEW_H
#define REVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include "widget.h"
#include <QTextEdit>
#include <QMessageBox>
class Review :public QWidget
{
    Q_OBJECT
public:
    Review();
    QPushButton *startButton;
    QPushButton *checkButton;
    QPushButton *returnButton;
    QPushButton *LookButton;
    QTextEdit   *explainedit;
    QTextEdit   *inPutedit;
    struct word{
        QString words;
        QString explain;
    };
    word words[15];
    int number;
public slots:
    void onStart();
    void onCheck();
    void onLook();
    void onReturn();
};

#endif // REVIEW_H
