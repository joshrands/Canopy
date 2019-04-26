#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>

//#include "Data.h"

/*
 * Frame button class that is a frame but has button capabilities
 *
*/
class FrameButton : public QFrame
{
public:
    FrameButton();

//    LocalEmailData email;

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

    virtual void onClick() = 0;

    QPoint lastPoint;
    QPoint clickPoint;

};

class EmailHeaderFrame : public FrameButton
{
public:
    void setEmailData(QString sender, QString receiver,
                      QString header, QString date);

    void setContentFileInfo(QString file, int line) { this->contentFile = file;
                                                      this->contentLine = line; }

    void displaySender();
    void displayReceiver();

protected:
    void onClick();

    QLabel* sendLabel;
    QLabel* receiveLabel;
    QLabel* headerLabel;
    QLabel* dateLabel;

    QString sender;
    QString receiver;
    QString header;
    QString date;

    QString contentFile;
    int contentLine;
};

class KeywordFrame : public QFrame
{
public:
    KeywordFrame(QString word);

    QString word;

    QPushButton* button;
};

#endif // FRAMEBUTTON_H
