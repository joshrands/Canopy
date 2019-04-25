#include "FrameButton.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

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

        qDebug() << "clicked";
        // open email window
//        EmailWindow* win = new EmailWindow();
//        win->setEmailData(this->email);

        //Qt::WindowFlags flags = windowFlags();
        //win->setWindowFlags(flags | Qt::WindowStaysOnTopHint);

        //win->show();
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

KeywordFrame::KeywordFrame(QString word)
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);

    this->word = word;

    QLabel* label = new QLabel(word);
    label->setAlignment(Qt::AlignLeft);

    button = new QPushButton();
    button->setText("Remove");

    this->layout()->addWidget(label);
    this->layout()->addWidget(button);
}
