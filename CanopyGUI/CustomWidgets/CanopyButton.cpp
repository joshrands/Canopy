#include "CanopyButton.h"

CanopyButton::CanopyButton()
{
//    this->setStyleSheet(QString("background-color: #F89939; color: rgb(255, 255, 255)"));//, color:#F89939; "));
}

void CanopyButton::setPressed()
{
    this->setStyleSheet(QString("background-color: #F89939; color: rgb(255, 255, 255)"));//, color:#F89939; "));
}

void CanopyButton::setDepressed()
{
    this->setStyleSheet(QString("background-color: white; color: rgb(0, 0, 0)"));//, color:#F89939; "));
}
