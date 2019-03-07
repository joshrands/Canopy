#include "FrameButton.h"

FrameButton::FrameButton()
{
    // enable mouse tracking
    this->setAttribute(Qt::WA_Hover);
    this->setMouseTracking(true);

    this->setStyleSheet(":hover {background-color: black;");
}

void FrameButton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        clickPoint = event->pos();
//        qDebug() << "FrameButton clicked";

        // open email window

    }
}

void FrameButton::mouseMoveEvent(QMouseEvent *event)
{
    lastPoint = event->pos();
//    qDebug() << "Hover";
}

void FrameButton::enterEvent(QEvent *)
{
//    qDebug() << "Enter";
    this->setStyleSheet("background-color: gray;");
}

void FrameButton::leaveEvent(QEvent *)
{
//    qDebug() << "Leave";
    this->setStyleSheet("background-color: white;");
}
