#include "EmailWindow.h"
#include "ui_EmailWindow.h"
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QDebug>

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

    // get html
//    qDebug() << email.parentFileName;

    QFile file(email.parentFileName);
    if (file.exists())
        qDebug() << "File exists";

    QString html;
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        for (int i = 0; i < email.htmlLocation; i++)
        {
            in.readLine();
        }

        QString line;
        line = in.readLine();

        html = QString("");
        for (int i = 0; i < email.htmlLength; i++)
        {
            line = in.readLine();

            // parse some html
            if (line.length() == 76)
                line = line.left(75);
            // TODO: REMOVE THIS
            if (line.right(1) == "=")
                line = line.left(line.length() - 2);

            line.replace("=A0","\n");
            line.replace("=0A","\n");
            line.replace("=08","\t");
            line.replace("=09","\t");
            line.replace("=20"," ");
            line.remove("=C");

            //            if (line.contains(""))

            html += line;
        }

    }
    else
    {
        html = errorHTML;
    }

    file.close();

    ui->htmlWindow->setHtml(html);
}

void EmailWindow::on_backButton_clicked()
{
   this->hide();
}
