#include "SessionWindow.h"
#include "ui_SessionWindow.h"

#include <QDesktopWidget>

SessionWindow::SessionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SessionWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}

SessionWindow::~SessionWindow()
{
    delete ui;
}
