#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    ui->fileFrame->setStyleSheet("background-color: white;");
    ui->browseButton->setStyleSheet("background-color: pale gray;");
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
