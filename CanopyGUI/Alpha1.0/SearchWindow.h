#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
//#include "../CanopyParser/EmailParser.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FrameButton.h"
#include <QSignalMapper>

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
    void setUserEmail(QString email) { this->userEmail = email; }

public slots:
    void removeKeyword(QString word);

private slots:
    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_doSearchButton_clicked();

    void on_inButton_clicked();

    void on_outButton_clicked();

    void on_closeButton_clicked();

    void on_addKeywordButton_clicked();

    void on_wordFreqFilter_textChanged(const QString &arg1);

private:
    Ui::SearchWindow *ui;

    QList<LocalEmailData> emailData;
    QList<LocalEmailData> displayEmails;

    QString filePath;
    QString fileName;
    QString suspectName;
    int warrantNumber;
    QString userEmail; // email of suspect

    // data analysis input
    QList<QString> keywordFilters;
    QDateTime startDateFilter;
    QDateTime endDateFilter;

    // auto generated data analytics
    QList<WordFreq> wordFreqData;
    QList<WordFreq> wordFreqDisplay;
    QList<QFrame*> wordFreqFrames;

    // email header display
    int emailCount;
    QList<FrameButton*> emailFrames;

    // keyword filter display
    QList<KeywordFrame*> keywordFrames;
    QSignalMapper* signalMapper;

    bool inBtnState;
    bool outBtnState;

    void getFilterInput();

    void populateEmailHeaders(); // fill header fields for email in GUI
    void sortDisplayEmails();	// put display emails in chronological order
    bool emailLessThan(const LocalEmailData* d1, const LocalEmailData* d2);

    void populateWordFreq(); 	// fill gui for word freq
    void applyEmailFilters();		// perform analytics as specified by user
    void getWordFrequency();	// find word frequency for all words

};

#endif // SEARCHWINDOW_H
