#include "EmailWindow.h"
#include "ui_EmailWindow.h"
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

EmailWindow::EmailWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmailWindow)
{
    ui->setupUi(this);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}

EmailWindow::~EmailWindow()
{
    delete ui;
}

void EmailWindow::setEmailData(EmailData email)
{
    this->email = email;

    ui->receiverLabel->setText("To: " + email.receiverAddress);
    ui->senderLabel->setText("From: " + email.senderAddress);
    ui->subjectLabel->setText("Subject: " + email.subjectLine);
    ui->dateLabel->setText("Date: " + email.dateString);
    //    ui->dateLabel->setText("Date: " + email.dateTime.date().toString());

    QString htmlString = QStringLiteral("<!DOCTYPE html>"
            "<html>"
            "<body>"
            ""
            "<h1>My First Heading</h1>"
            ""
            "<p>My first paragraph.</p>"
            ""
            "</body>"
            "</html>");

    ui->htmlWindow->setHtml(htmlString);
}

void EmailWindow::on_backButton_clicked()
{
   this->hide();
}
