#ifndef ADDDATAWINDOW_H
#define ADDDATAWINDOW_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class AddDataWindow;
}

class AddDataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDataWindow(QWidget *parent = 0);
    ~AddDataWindow();

    void setCreateSession(bool val);

private slots:
    void on_browseButton_clicked();

    void on_createSessionButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddDataWindow *ui;

    bool session;

    QString dataPath;
    QString dataName;

    void populateProviderBox();
    bool checkValidFields();
};

#endif // ADDDATAWINDOW_H
