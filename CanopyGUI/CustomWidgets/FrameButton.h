#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>

#include "CanopyButton.h"
//#include "Data.h"

/*
 * Frame button class that is a frame but has button capabilities
 *
*/
class FrameButton : public QFrame
{
    Q_OBJECT

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

signals:
    void clicked();

};

class EmailHeaderFrame : public FrameButton
{
Q_OBJECT
public:
    void setEmailData(int num, QString sender, QString receiver,
                      QString header, QString date);

    void setContentFileInfo(QString file, int line) { this->contentFile = file;
                                                      this->contentLine = line; }

    void displaySender();
    void displayReceiver();

    QString getContentPath() { return this->contentFile; }
    int getContentLine() { return this->contentLine; }
    QString getSubjectLine() { return this->header; }

    FlagButton* flag;
    QLabel* emailNumLabel;
    int emailNum;

public slots:
    void toggleFlag();

protected:
    void makeLabels();
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
