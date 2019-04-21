#ifndef SESSIONWINDOW_H
#define SESSIONWINDOW_H

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

private slots:
    void on_addDataButton_clicked();

    // custom slot
    void tabButtonPressed();

private:
    Ui::SessionWindow *ui;

    // path to the session file
    QString sessionFilePath;

    // store content in Data class
    // Data class has a ContentWindow
    QList<Data*> data;

    Data* activeData;
    QString dataFilePath;
    QString activeDataName;

    void displayNewContent();
};

#endif // SESSIONWINDOW_H
