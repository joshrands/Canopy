#include "FrameButton.h"

FrameButton::FrameButton()
{
    // enable mouse tracking
    this->setAttribute(Qt::WA_Hover);
    this->setMouseTracking(true);

//    this->setStyleSheet(":hover {background-color: black;");
}

void FrameButton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        clickPoint = event->pos();

        // open email window
        EmailWindow* win = new EmailWindow();
        win->setEmailData(this->email);
        win->show();
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
