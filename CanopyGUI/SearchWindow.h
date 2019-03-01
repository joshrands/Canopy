#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_backButton_clicked();

private:
    Ui::SearchWindow *ui;

    QString fileName;
    QString suspectName;
    int warrantNumber;
};

#endif // SEARCHWINDOW_H
