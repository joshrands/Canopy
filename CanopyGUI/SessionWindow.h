#ifndef SESSIONWINDOW_H
#define SESSIONWINDOW_H

#include <QDir>
#include <QMainWindow>

#include <Data.h> // also has ContentWindow

namespace Ui {
class SessionWindow;
}

class SessionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SessionWindow(QWidget *parent = 0);
    ~SessionWindow();

    void addData(Data* data);

    void setSessionDirectory(QString path) { this->sessionDirectory = path;
                                           QDir().mkdir(path + "/session");
                                           QDir().mkdir(path + "/session/working");
                                           QDir().mkdir(path + "/session/engine");
                                           }

private slots:
    void on_addDataButton_clicked();

    // custom slot
    void tabButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::SessionWindow *ui;

    // path to the session file
    QString sessionDirectory;

    // store content in Data class
    // Data class has a ContentWindow
    QList<Data*> data;

    Data* activeData;
    QString dataFilePath;
    QString activeDataName;

    void displayNewContent();
};

#endif // SESSIONWINDOW_H
