#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFileDialog>
#include <QDebug>
#include <QStringList>

#include "SearchWindow.h"

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = 0);
    ~WelcomeWindow();

    void initialize();

    void setFileName(QString name) { this->fileName = name; }
    void setSuspectName(QString name) { this->suspectName = name; }
    void setWarrantNumber(int num) { this->warrantNumber = num; }

private slots:
    void on_browseButton_clicked();

    void on_suspectNameField_editingFinished();

    void on_warrantNumberField_editingFinished();

    void on_evaluateButton_clicked();

private:
    Ui::WelcomeWindow *ui;

    QList<QString> validFileTypes;
    QString currentDirectory;

    QString fileName;
    QString suspectName;
    int warrantNumber;

    void checkEvaluate();
    QString getFileNameFromPath(QString path);
    void getFieldValues();
};

#endif // WELCOMEWINDOW_H
