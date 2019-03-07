#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
#include "../CanopyParser/EmailParser.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FrameButton.h"

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
    void setFilePath(QString path) { this->filePath = path; }

private slots:
    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_doSearchButton_clicked();

    void on_inButton_clicked();

    void on_outButton_clicked();

private:
    Ui::SearchWindow *ui;

    QList<EmailData> emailData;
    QString filePath;
    QString fileName;
    QString suspectName;
    int warrantNumber;
    QString userEmail; // email of suspect

    // email header display
    int emailCount;
    QList<FrameButton*> emailFrames;

    bool inBtnState;
    bool outBtnState;

    void populateEmailHeaders(); // fill header fields for email in GUI
};

#endif // SEARCHWINDOW_H
