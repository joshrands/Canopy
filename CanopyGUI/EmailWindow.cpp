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

    // remove 'x'
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

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

    QString errorHTML = QStringLiteral("<!DOCTYPE html>"
            "<html>"
            "<body>"
            ""
            "<h1>Error</h1>"
            ""
            "<p>There was an error loading this email's content</p>"
            ""
            "</body>"
            "</html>");

    ui->htmlWindow->setHtml(errorHTML);
}

void EmailWindow::on_backButton_clicked()
{
   this->hide();
}
