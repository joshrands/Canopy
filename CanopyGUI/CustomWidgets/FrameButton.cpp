#include "FrameButton.h"
#include "CanopyButton.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>

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

        emit clicked();
//        this->onClick();

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

void EmailHeaderFrame::onClick()
{
    qDebug() << "Email clicked";

}

void EmailHeaderFrame::setEmailData(int num, QString sender, QString receiver,
                                    QString header, QString date)
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);
    this->setStyleSheet("background-color: white;");

    this->emailNum = num + 1;
    emailNumLabel = new QLabel();
    emailNumLabel->setFixedWidth(22);
    emailNumLabel->setText(QString::number(emailNum));

    this->sender = sender;
    sendLabel = new QLabel();
    sendLabel->setText(sender);

    this->receiver = receiver;
    receiveLabel = new QLabel();
    receiveLabel->setText(receiver);

    this->header = header;
    headerLabel = new QLabel();
    headerLabel->setText(header);

    this->date = date;
    dateLabel = new QLabel();
    dateLabel->setText(date);


    //this->layout()->addWidget(sendLabel);
    //this->layout()->addWidget(receiveLabel);
}

void EmailHeaderFrame::displaySender()
{
    // add filter buttons
    flag = new FlagButton();

    connect(flag, SIGNAL(clicked()), this, SLOT(toggleFlag()));

    this->layout()->addWidget(emailNumLabel);
    this->layout()->addWidget(flag);

    this->layout()->addWidget(sendLabel);
    this->layout()->addWidget(headerLabel);
    this->layout()->addWidget(dateLabel);
}

void EmailHeaderFrame::displayReceiver()
{
    // add filter buttons
    flag = new FlagButton();
    connect(flag, SIGNAL(clicked()), this, SLOT(toggleFlag()));

    this->layout()->addWidget(emailNumLabel);
    this->layout()->addWidget(flag);

    this->layout()->addWidget(receiveLabel);
    this->layout()->addWidget(headerLabel);
    this->layout()->addWidget(dateLabel);
}

void EmailHeaderFrame::toggleFlag()
{
    qDebug() << "Toggling flag";
    qDebug() << flag->isToggled();

    if (flag->isToggled())
    {
        flag->setOff();
    }
    else
    {
        flag->setOn();
    }

    flag->toggle();
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
