#include "jeffpushbutton.h"


JeffPushButton::JeffPushButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("background-color: rgb(0, 255, 10);");
    return;
}

JeffPushButton::~JeffPushButton()
{
    return;
}
