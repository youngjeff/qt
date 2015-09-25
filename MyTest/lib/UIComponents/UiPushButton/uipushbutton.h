#ifndef UIPUSHBUTTON_H
#define UIPUSHBUTTON_H

#include "uipushbutton_global.h"

class UIPUSHBUTTONSHARED_EXPORT UiPushButton  :public QPushButton
{
    Q_OBJECT
public:
    UiPushButton(QWidget *parent = 0);
    ~UiPushButton();
};

#endif // UIPUSHBUTTON_H
