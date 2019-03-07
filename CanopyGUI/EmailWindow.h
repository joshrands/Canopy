#ifndef EMAILWINDOW_H
#define EMAILWINDOW_H

#include <QMainWindow>
#include "../CanopyParser/EmailParser.h"

namespace Ui {
class EmailWindow;
}

class EmailWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmailWindow(QWidget *parent = 0);
    ~EmailWindow();

    void setEmailData(EmailData email);

private slots:
    void on_backButton_clicked();

private:
    Ui::EmailWindow *ui;

    EmailData email;
};

#endif // EMAILWINDOW_H
