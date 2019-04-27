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

void EmailHeaderFrame::setEmailData(QString sender, QString receiver,
                                    QString header, QString date)
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);
    this->setStyleSheet("background-color: white;");

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
    CanopyButton* importantFilter = new CanopyButton();
    importantFilter->setFixedHeight(25);
    importantFilter->setFixedWidth(25);
//    importantFilter->setDepressed();

    QPixmap pix("../images/important-not-selected.png");
    QIcon icon(pix);
    importantFilter->setIcon(icon);
    importantFilter->setIconSize(pix.rect().size());

/*    QRect rect(0, 0, 20, 20);
    QRegion region(rect, QRegion::Ellipse);
    importantFilter->setMask(region);
*/
    this->layout()->addWidget(importantFilter);

    this->layout()->addWidget(sendLabel);
    this->layout()->addWidget(headerLabel);
    this->layout()->addWidget(dateLabel);
}

void EmailHeaderFrame::displayReceiver()
{
    // add filter buttons
    FlagButton* importantFilter = new FlagButton();

    this->layout()->addWidget(importantFilter);

    this->layout()->addWidget(receiveLabel);
    this->layout()->addWidget(headerLabel);
    this->layout()->addWidget(dateLabel);
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
