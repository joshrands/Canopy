#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
#include "../CanopyParser/EmailParser.h"

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();

    void initialize();

    void setFileName(QString name) { this->fileName = name; }
    void setSuspectName(QString name) { this->suspectName = name; }
    void setWarrantNumber(int num) { this->warrantNumber = num; }
    void setEmailData(QList<EmailData> data) { this->emailData = data; }

private slots:
    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_doSearchButton_clicked();

    void on_inButton_clicked();

    void on_outButton_clicked();

private:
    Ui::SearchWindow *ui;

    QList<EmailData> emailData;
    QString fileName;
    QString suspectName;
    int warrantNumber;

    bool inBtnState;
    bool outBtnState;
};

#endif // SEARCHWINDOW_H
