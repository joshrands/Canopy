#include "ContentWindow.h"
#include "ui_ContentWindow.h"

ContentWindow::ContentWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ContentWindow)
{
    ui->setupUi(this);
}

ContentWindow::~ContentWindow()
{
    delete ui;
}

EmailContentWindow::EmailContentWindow()
{
    ui->title->setText("EMAIL");
}

HtmlContentWindow::HtmlContentWindow()
{
    ui->title->setText(("FACEBOOK"));
}
