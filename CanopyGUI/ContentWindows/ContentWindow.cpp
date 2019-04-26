#include "ContentWindow.h"
#include "ui_ContentWindow.h"
#include "../CanopyParser/ParseEmail.h"

#include <QFuture>
#include <QLabel>
#include <QHBoxLayout>

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

void ContentWindow::initializeDir(QString sessionPath, QString contentName)
{
    this->sessionFilePath = sessionPath;
    this->contentName = contentName;

    // make folder for can data
    QString dir = QString(this->sessionFilePath + "/session/" + this->contentName);
    QDir().mkdir(dir);
    // make .can and .ins files
    QFile canFile(dir + "/" + this->contentName + ".can");
    QFile insFile(dir + "/" + this->contentName + ".ins");
    QFile txtFile(this->sessionFilePath + "/session/working/" + this->contentName + ".txt");

    if (!canFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .can file.";
    }
    if (!insFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .ins file.";
    }
    if (!txtFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .txt file.";
    }

    canFile.close();
    insFile.close();
    txtFile.close();
}

EmailContentWindow::EmailContentWindow()
{
    this->page = 0;
    this->numCans = EMAILS_PER_PAGE;
    // create subfolders on top
    // create tab button

    // create title bar
    QLabel* emailTitle = new QLabel();
    emailTitle->setText(QString("Email"));

    QLabel* subjectTitle = new QLabel();
    subjectTitle->setText(QString("Subject Header"));

    QLabel* dateTitle = new QLabel();
    dateTitle->setText(QString("Date"));

    QHBoxLayout* layout = new QHBoxLayout();
    ui->headerFrame->setLayout(layout);

    ui->headerFrame->layout()->addWidget(emailTitle);
    ui->headerFrame->layout()->addWidget(subjectTitle);
    ui->headerFrame->layout()->addWidget(dateTitle);

    // load emails!
    qDebug() << "Loading " << this->contentName;
}

void EmailContentWindow::parseDataFile(QString file)
{
    this->dataFilePath = file;

    /****************** PARSE FILE ******************/
    if (file.contains(QString(".mbox")))
    {
        // start a thread to parse this file
        QFuture<void> future = QtConcurrent::run(parseMBOX,
                                                 this->dataFilePath,
                                                 this->sessionFilePath,
                                                 this->contentName);
    }
}

HtmlContentWindow::HtmlContentWindow()
{
 //   ui->title->setText(("FACEBOOK"));

}

void HtmlContentWindow::parseDataFile(QString file)
{

}
