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

//    virtual void displayContent(QString filePath, int lineNum) = 0;

//    QThread thread;

    virtual void addDataTab(QString dataPath) = 0;
    bool atMaxPage = false;

protected:
    Ui::ContentWindow *ui;

    QString dataFilePath;
    QString sessionFilePath;
    QString contentName;


    bool debounce = false;

private slots:
    void on_backButton_clicked();

signals:
    void nextPageSignal();
    void prevPageSignal();

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
Q_OBJECT

public:
    EmailContentWindow(QWidget* parent = 0);

    static const int EMAILS_PER_PAGE = 50;

    void parseDataFile(QString file);

    void addHeaderFrame(EmailHeaderFrame* frame);

    int page;
    void loadPage(int num);
//    QList<EmailCan*> currentPage;
    QList<EmailHeaderFrame*> headerButtons;

    void addDataTab(QString dataPath);
//    void displayContent(QString filePath, int lineNum);

    CanopyButton* nextPageButton;
    CanopyButton* prevPageButton;

public slots:
    void displayContent(int id);
    void on_nextPage_clicked();
    void on_prevPage_clicked();

protected:

};

class HtmlContentWindow : public ContentWindow
{
Q_OBJECT
public:
    HtmlContentWindow(QWidget* parent = 0);

    void parseDataFile(QString file);

    void addDataTab(QString dataPath);

//    void displayContent(QString filePath, int lineNum);
};

#endif // CONTENTWINDOW_H
