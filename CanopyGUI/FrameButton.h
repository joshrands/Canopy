#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QDebug>
#include <QMouseEvent>
#include "../CanopyParser/EmailParser.h"

/*
 * Frame button class that is a frame but has button capabilities
 *
*/
class FrameButton : public QFrame
{
public:
    FrameButton();

    EmailData email;

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    QPoint lastPoint;
    QPoint clickPoint;

};

#endif // FRAMEBUTTON_H
