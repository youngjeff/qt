#ifndef JEFFPUSHBUTTON_H
#define JEFFPUSHBUTTON_H

#include "jeffpushbutton_global.h"

class JEFFPUSHBUTTONSHARED_EXPORT JeffPushButton : public QPushButton
{
    Q_OBJECT
public:
    JeffPushButton(QWidget *parent = 0);
    ~JeffPushButton();
};

#endif // JEFFPUSHBUTTON_H
