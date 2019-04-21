#include "ContentWindow.h"
#include "ui_ContentWindow.h"
#include "../CanopyParser/ParseEmail.h"
#include <QFuture>

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
//    ui->title->setText("EMAIL");

}

void EmailContentWindow::parseDataFile(QString file)
{
    if (file.contains(QString(".mbox")))
    {
        QFuture<void> future = QtConcurrent::run(parseMBOX, file, this->sessionFilePath);
    }
}

HtmlContentWindow::HtmlContentWindow()
{
 //   ui->title->setText(("FACEBOOK"));

}

void HtmlContentWindow::parseDataFile(QString file)
{

}
