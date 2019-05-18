#ifndef CASEDATA_H
#define CASEDATA_H

/*
 * CaseData: Class for storing different types of data inputs and managing
 * differences between them
 *
*/

#include <./ContentWindows/ContentWindow.h>
#include "../CanopyParser/ParseEmail.h"

#include <QDateTime>
#include <QStringList>
#include <QPushButton>
#include <QMainWindow>
#include <QSignalMapper>
#include <QObject>
#include <QWidget>

class Data;// : public Q_Ojbect;

class DataTabButton : public QPushButton
{
public:
    ContentWindow* window;
    QMainWindow* session;
    Data* data;
};

class Data : public QWidget
{
Q_OBJECT

public:
    explicit Data(QWidget* parent = 0);
    ~Data();

    static QStringList types;

    void setDataPath(QString val) { this->dataPath = val; }
    void setDataName(QString val) { this->dataName = val; }
    void setSuspectName(QString val) { this->suspectName = val; }
    void setSessionPath(QString val) { this->sessionPath = val; }

    QString getDataPath() { return dataPath; }
    QString getDataName() { return dataName; }
    QString getSuspectName() { return suspectName; }
    QString getSessionPath() { return sessionPath; }

    virtual void createWindow() = 0;
    virtual void getCanData(int start, int num) = 0;

    DataTabButton* tabButton;
    ContentWindow* window;

protected:
    QString dataPath;
    QString sessionPath;

    // name given by user
    QString dataName;
    QString suspectName;

    QSignalMapper* signalMapper;
    // content window associated with this data
};


/****** EMAIL DATA ******/

class EmailData : public Data
{
Q_OBJECT
public:
    EmailData(QWidget* parent = 0);
//    ~EmailData();

    void createWindow();
    void getCanData(int start, int num);

public slots:
    void nextPage();
    void prevPage();

};

/***********************/

/**** FACEBOOK DATA ****/
class HtmlData : public Data
{
public:

    void createWindow();
    void getCanData(int start, int num);
};

/***********************/

#endif // CASEDATA_H
