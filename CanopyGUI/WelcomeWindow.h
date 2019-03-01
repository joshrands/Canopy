#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFileDialog>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = 0);
    ~WelcomeWindow();

private slots:
    void on_browseButton_clicked();

    void on_suspectNameField_editingFinished();

    void on_warrantNumberField_editingFinished();

private:
    Ui::WelcomeWindow *ui;

    QList<QString> validFileTypes;
    QString currentDirectory;
    QString fileName;

    void checkEvaluate();
};

#endif // WELCOMEWINDOW_H
