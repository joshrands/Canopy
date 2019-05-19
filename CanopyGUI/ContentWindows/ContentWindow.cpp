#include "ContentWindow.h"
#include "ui_ContentWindow.h"
#include "../CanopyParser/ParseEmail.h"
#include "./CustomWidgets/CanopyButton.h"

#include <QFuture>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

ContentWindow::ContentWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ContentWindow)
{
    ui->setupUi(this);

    ui->htmlFrame->hide();
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

EmailContentWindow::EmailContentWindow(QWidget* parent)
    : ContentWindow(parent)
{
    this->page = 0;
    this->numCans = EMAILS_PER_PAGE;
    // create subfolders on top
    // create tab button
    // create Inbox tab for all emails
    CanopyButton* inbox = new CanopyButton();
    inbox->setText(QString("Inbox"));
    inbox->setPressed();

    QHBoxLayout* tabLayout = new QHBoxLayout();
    tabLayout->setAlignment(Qt::AlignLeft);
    ui->tabFrame->setLayout(tabLayout);
    ui->tabFrame->layout()->addWidget(inbox);

    // create Sent/Received filters
    CanopyButton* sent = new CanopyButton();
    sent->setText(QString("Sent"));
    sent->setDepressed();
    CanopyButton* recv = new CanopyButton();
    recv->setText(QString("Received"));
    recv->setPressed();

    // TODO: Link buttons with filters

    QHBoxLayout* filterLayout = new QHBoxLayout();
    filterLayout->setAlignment(Qt::AlignRight);
    ui->filterFrame->setLayout(filterLayout);
    ui->filterFrame->layout()->addWidget(sent);
    ui->filterFrame->layout()->addWidget(recv);

    // create next and back page buttons
    CanopyButton* prevPage = new CanopyButton();
    prevPage->setText(QString("Previous Page"));
    prevPage->setPressed();
    this->prevPageButton = prevPage;

    CanopyButton* nextPage = new CanopyButton();
    nextPage->setText(QString("Next Page"));
    nextPage->setPressed();
    this->nextPageButton = nextPage;

    // TODO: make these buttons work
    // SIGNAL CAUGHT IN DATA
    //    connect(nextPage, SIGNAL(clicked(bool)), this, SLOT(on_nextPage_clicked()));
//    connect(prevPage, SIGNAL(clicked(bool)), this, SLOT(on_prevPage_clicked()));

    QHBoxLayout* baseLayout = new QHBoxLayout();
    baseLayout->setAlignment(Qt::AlignCenter);
    ui->baseFrame->setLayout(baseLayout);
    ui->baseFrame->layout()->addWidget(prevPage);
    ui->baseFrame->layout()->addWidget(nextPage);

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

    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->content->setLayout(vLayout);

    // load emails!
    qDebug() << "Loading " << this->contentName;
}

// TODO: EMIT A SIGNAL AND CATCH IN DATA.cpp
void EmailContentWindow::on_nextPage_clicked()
{
    // TODO: Check if max page
    if (!atMaxPage)
    {
        qDebug() << "Displaying next page";
        emit nextPageSignal();

        this->page++;
    }
}

void EmailContentWindow::on_prevPage_clicked()
{
    if (this->page > 0)
    {
        qDebug() << "Displaying previous page";
        emit prevPageSignal();

        this->page--;
    }
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
        // start a thread to perform analytics on parsed data or parse in the parseMBOX
    }
}

void EmailContentWindow::addHeaderFrame(EmailHeaderFrame *frame)
{
    ui->content->layout()->addWidget(frame);
    this->headerButtons.append(frame);
}

void EmailContentWindow::addDataTab(QString dataPath)
{

}

void EmailContentWindow::displayContent(int id)
{
    if (!debounce)
    {
        debounce = true;
        qDebug() << id;
        qDebug() << "Displaying content";
        qDebug() << this->headerButtons.at(id)->getContentPath();
        qDebug() << this->headerButtons.at(id)->getContentLine();
        qDebug() << this->headerButtons.at(id)->getSubjectLine();

        QFile txtFile(this->headerButtons.at(id)->getContentPath());
        if (!txtFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Error opening content file";
            // put error html
        }
        else
        {
            int line = this->headerButtons.at(id)->getContentLine();
            qDebug() << "Seeking to byte location: " << line*(LINE_LENGTH);
            txtFile.seek(line*(LINE_LENGTH + 1));
            qDebug() << "Seek success";

            QTextStream in(&txtFile);

            // TODO: REMOVE THIS ONCE SEEK IS WORKING
            // cheat for seek
           /* for (int i = 0; i < line; i++)
            {
                QString inLine = in.readLine();
                if (inLine.length() != 100)
                {
                    qDebug() << i << ": " << inLine;
                }
            }
            */    // REMOVE THIS ^^^

            qDebug() << "Text stream created";

            QString inLine = in.readLine();
            qDebug() << inLine;
            // CHEATING
            while (inLine.length() < LINE_LENGTH)
            {
                inLine = in.readLine();
                qDebug() << inLine;
            }

            qDebug() << inLine;
            QStringList params = inLine.split(",");
            qDebug() << params.at(0);
            int length = params.at(1).toInt();

            QString html("");
            for (int i = 0; i < length; i++)
            {
                html += in.readLine();
//                qDebug() << "Writing line of html";
            }

            ui->htmlContent->setHtml(html);
            txtFile.close();

            qDebug() << "HTML parsed";
        }

        // display email!
        ui->contentFrame->hide();
        ui->htmlFrame->show();
    }
}

HtmlContentWindow::HtmlContentWindow(QWidget* parent)
    : ContentWindow(parent)
{
    //   ui->title->setText(("FACEBOOK"));

}

void HtmlContentWindow::parseDataFile(QString file)
{

}

void HtmlContentWindow::addDataTab(QString dataPath)
{

}

void ContentWindow::on_backButton_clicked()
{
    ui->htmlFrame->hide();
    ui->contentFrame->show();
    this->debounce = false;
}
