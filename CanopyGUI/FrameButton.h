#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QDebug>
#include <QMouseEvent>
#include "EmailWindow.h"
#include <QPushButton>

/*
 * Frame button class that is a frame but has button capabilities
 *
*/
class FrameButton : public QFrame
{
public:
    FrameButton();

    LocalEmailData email;

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    QPoint lastPoint;
    QPoint clickPoint;

};

class KeywordFrame : public QFrame
{
public:
    KeywordFrame(QString word);

    QString word;

    QPushButton* button;
};

#endif // FRAMEBUTTON_H
