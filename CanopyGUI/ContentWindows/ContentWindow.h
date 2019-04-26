#ifndef CONTENTWINDOW_H
#define CONTENTWINDOW_H

#include <QFrame>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include "CustomWidgets/FrameButton.h"

namespace Ui {
class ContentWindow;
}

class ContentWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ContentWindow(QWidget *parent = 0);
    ~ContentWindow();

    // how many can objects stored in ram for this type of content
    int numCans = 0;
    virtual void parseDataFile(QString file) = 0;

//    void setSessionPath(QString path) { this->sessionFilePath = path; }
//    void setContentName(QString name) { this->contentName = name; }
    void initializeDir(QString sessionPath, QString name);
    QString getContentName() { return this->contentName; }

    QThread thread;

protected:
    Ui::ContentWindow *ui;

    QString dataFilePath;
    QString sessionFilePath;
    QString contentName;
};


/* Email helper classes */
class EmailCan
{
public:
    static const int MAX_SUBJECT_LENGTH = 25;

    QString sender;
    QString receiver;
    QString subject;
    QString date;
    QDateTime dateTime;

    QString txtFilePath;
    int lineNum;
};

class EmailContentWindow : public ContentWindow
{
public:
    EmailContentWindow();

    static const int EMAILS_PER_PAGE = 50;

    void parseDataFile(QString file);

    int page;
    void loadPage(int num);
    QList<EmailCan> currentPage;
    QList<FrameButton> headerButtons;
};

class HtmlContentWindow : public ContentWindow
{
public:
    HtmlContentWindow();

    void parseDataFile(QString file);
};

#endif // CONTENTWINDOW_H
