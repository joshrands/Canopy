#include "EmailContentWindow.h"
#include "ui_EmailContentWindow.h"

EmailContentWindow::EmailContentWindow(QWidget *parent) :
    ContentWindow,
    ui(new Ui::EmailContentWindow)
{
    ui->setupUi(this);
}

EmailContentWindow::~EmailContentWindow()
{
    delete ui;
}
