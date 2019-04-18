#include "StartWindow.h"
#include "ui_StartWindow.h"

#include <QDesktopWidget>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}

StartWindow::~StartWindow()
{
    delete ui;
}
