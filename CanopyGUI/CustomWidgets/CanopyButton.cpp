#include "CanopyButton.h"
#include <QBitmap>

CanopyButton::CanopyButton()
{
//    this->setDepressed();
}

void CanopyButton::setPressed()
{
    this->setStyleSheet(QString("background-color: #F89939; color: rgb(255, 255, 255)"));//, color:#F89939; "));
}

void CanopyButton::setDepressed()
{
    this->setStyleSheet(QString("background-color: white; color: rgb(100, 100, 100)"));//, color:#F89939; "));
}

FlagButton::FlagButton()
{
    this->setFixedHeight(30);
    this->setFixedWidth(30);

    this->setOff();
    this->toggled = false;
}

void FlagButton::setOn()
{
    QRect rect(2, 2, 26, 26);
    QRegion region(rect, QRegion::Ellipse);
    this->setMask(region);

    QPixmap pix("/home/josh/CanopyIntel/Canopy/images/orange-important.png");
    int size = 24;

    QPixmap map = pix.scaled(size, size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon icon(map);

    this->setIcon(icon);
    this->setIconSize(pix.rect().size());
}

void FlagButton::setOff()
{
    QRect rect(2, 2, 26, 26);
    QRegion region(rect, QRegion::Ellipse);
    this->setMask(region);

    QPixmap pix("/home/josh/CanopyIntel/Canopy/images/important-not-select.png");
    int size = 24;

    QPixmap map = pix.scaled(size, size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon icon(map);

    this->setIcon(icon);
    this->setIconSize(pix.rect().size());
}
