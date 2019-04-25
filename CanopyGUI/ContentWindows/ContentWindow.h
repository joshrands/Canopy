#ifndef CONTENTWINDOW_H
#define CONTENTWINDOW_H

#include <QFrame>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

namespace Ui {
class ContentWindow;
}

class ContentWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ContentWindow(QWidget *parent = 0);
    ~ContentWindow();

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

class EmailContentWindow : public ContentWindow
{
public:
    EmailContentWindow();

    const int EMAILS_PER_PAGE = 50;

    void parseDataFile(QString file);

private:
    int page;

    void loadPage(int num);
};

class HtmlContentWindow : public ContentWindow
{
public:
    HtmlContentWindow();

    void parseDataFile(QString file);
};

#endif // CONTENTWINDOW_H
