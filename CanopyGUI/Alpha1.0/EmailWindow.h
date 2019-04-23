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

    void setEmailData(LocalEmailData email);

private slots:
    void on_backButton_clicked();

private:
    Ui::EmailWindow *ui;

    LocalEmailData email;

    QString errorHTML = QStringLiteral("<!DOCTYPE html>"
            "<html>"
            "<body>"
            ""
            "<h1>Error</h1>"
            ""
            "<p>There was an error loading this email's content</p>"
            ""
            "</body>"
            "</html>");
};

#endif // EMAILWINDOW_H
