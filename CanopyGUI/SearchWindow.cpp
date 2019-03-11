#include "SearchWindow.h"
#include "WelcomeWindow.h"

#include "ui_SearchWindow.h"

#include <QDesktopWidget>

SearchWindow::SearchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    ui->suspectFrame->setStyleSheet("background-color: gray;");
    ui->infoFrame->setStyleSheet("background-color: gray;");
    ui->freqFrame->setStyleSheet("background-color: gray;");
    ui->outButton->setStyleSheet("background-color: black;");

    ui->searchFrame->setVisible(false);

    this->inBtnState = false;
    this->outBtnState = true;
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::initialize()
{
    // initialize fields
    ui->suspectNameLabel->setText(this->suspectName);
    ui->warrantNumberLabel->setText(QString::number(this->warrantNumber));

    QFile file(this->filePath);
    qDebug() << "File size: " << file.size()/1000000000.0;
    ui->fileSizeLabel->setText(QString::number(file.size()/1000000000.0) + QString(" GB"));

    file.close();

    // parse input file
    this->emailData = parseEmailWarrant(this->filePath);

    // set up email header list scroll area
    ui->emailHeaderList->widget()->setLayout(new QVBoxLayout());
    ui->emailHeaderList->widget()->layout()->setAlignment(Qt::AlignTop);

    ui->freqCountScrollArea->widget()->setLayout(new QVBoxLayout());
    ui->freqCountScrollArea->widget()->layout()->setAlignment(Qt::AlignTop);

    populateEmailHeaders();

    getWordFrequency();
    populateWordFreq();
}

void SearchWindow::populateEmailHeaders()
{
    // delete existing emails
    for (int i = 0; i < this->emailFrames.length(); i++)
    {
        delete emailFrames.at(i);
    }

    this->emailFrames.clear();

    for (int i = 0; i < this->emailData.length(); i++)
    {
        EmailData email = this->emailData.at(i);

        // should we display this email?
        bool displayEmail = false;

        if (email.senderAddress == this->userEmail && outBtnState)
            displayEmail = true; // outbound enabled
        else if (email.receiverAddress == this->userEmail && inBtnState)
            displayEmail = true; // inbound enabled

        // display email in GUI
        if (displayEmail)
        {
            QString emailLabelText;
            if (email.senderAddress == this->userEmail)
            {
                emailLabelText = QString("To: ");
                emailLabelText = emailLabelText + email.receiverAddress;
            }
            else
            {
                emailLabelText = QString("From: ");
                emailLabelText = emailLabelText + email.senderAddress;
            }

            QHBoxLayout* layout = new QHBoxLayout();

            // create frame and set horizontal layout
            FrameButton* frame = new FrameButton();
            frame->setLayout(layout);
            frame->setFrameShape(QFrame::Box);
            frame->email = email;

            QLabel* emailLabel = new QLabel();
            emailLabel->setText(emailLabelText);
            emailLabel->setAlignment(Qt::AlignLeft);

            QLabel* subjectLabel = new QLabel();
            subjectLabel->setText(email.subjectLine);
            subjectLabel->setAlignment(Qt::AlignCenter);
            subjectLabel->setAlignment(Qt::AlignTop);

            QLabel* dateLabel = new QLabel();
            dateLabel->setText(email.dateString);//email.dateTime.date().toString());
            dateLabel->setAlignment(Qt::AlignRight);
            dateLabel->setAlignment(Qt::AlignTop);

            frame->layout()->addWidget(emailLabel);
            frame->layout()->addWidget(subjectLabel);
            frame->layout()->addWidget(dateLabel);
            frame->setFixedHeight(40);
            frame->setFixedWidth(710);

            this->emailFrames.append(frame);

            // add frame to email scroll area
            ui->emailHeaderList->widget()->layout()->addWidget(frame);
        }
    }
}

void SearchWindow::on_backButton_clicked()
{
    WelcomeWindow* win = new WelcomeWindow();
    win->setFileName(this->fileName);
    win->setSuspectName(this->suspectName);
    win->setWarrantNumber(this->warrantNumber);

    win->initialize();
    win->show();

    hide();
}

void SearchWindow::on_searchButton_clicked()
{
    ui->searchFrame->setVisible(true);
    ui->emailFrame->setVisible(false);
}

void SearchWindow::on_doSearchButton_clicked()
{
    ui->searchFrame->setVisible(false);
    ui->emailFrame->setVisible(true);

    this->doDataAnalytics();
}

void SearchWindow::on_inButton_clicked()
{
    if (this->inBtnState)
    {
        inBtnState = false;
        ui->inButton->setStyleSheet("background-color: white;");
    }
    else
    {
        inBtnState = true;
        ui->inButton->setStyleSheet("background-color: black;");
    }

    this->populateEmailHeaders();
}

void SearchWindow::on_outButton_clicked()
{
    if (this->outBtnState)
    {
        outBtnState = false;
        ui->outButton->setStyleSheet("background-color: white;");
    }
    else
    {
        outBtnState = true;
        ui->outButton->setStyleSheet("background-color: black;");
    }

    this->populateEmailHeaders();
}

void SearchWindow::on_closeButton_clicked()
{
   qApp->closeAllWindows();
}

void SearchWindow::populateWordFreq()
{
    // populate gui based off information from getWordFrequency
    for (int i = 0; i < wordFreqData.size(); i++)
    {
        WordFreq word = wordFreqData.at(i);

        qDebug() << word.word;
        QHBoxLayout* layout = new QHBoxLayout();

        // create frame and set horizontal layout
        QFrame* frame = new QFrame();
        frame->setLayout(layout);
        frame->setFrameShape(QFrame::Box);

        QLabel* rankLabel = new QLabel();
        rankLabel->setText(QString::number(word.rank));
        rankLabel->setAlignment(Qt::AlignLeft);

        QLabel* wordLabel = new QLabel();
        wordLabel->setText(word.word);
        wordLabel->setAlignment(Qt::AlignCenter);
        wordLabel->setAlignment(Qt::AlignTop);

        QLabel* countLabel = new QLabel();
        countLabel->setText(QString::number(word.count));//email.dateTime.date().toString());
        countLabel->setAlignment(Qt::AlignRight);
        countLabel->setAlignment(Qt::AlignTop);

        frame->layout()->addWidget(rankLabel);
        frame->layout()->addWidget(wordLabel);
        frame->layout()->addWidget(countLabel);
        frame->setFixedHeight(40);
        frame->setFixedWidth(230);

        ui->freqCountScrollArea->widget()->layout()->addWidget(frame);
    }
}

void SearchWindow::doDataAnalytics()
{
    // call data analytics functions on email content

    qDebug() << "Performing data analytics on email data...";
}

void SearchWindow::getWordFrequency()
{
    // call Canopy Data functions for word frequency on all email content

    WordFreq word1(1, QString("rhino"), 22);
    WordFreq word2(2, QString("tiger"), 15);
    WordFreq word3(3, QString("cupcake"), 11);

    wordFreqData.append(word1);
    wordFreqData.append(word2);
    wordFreqData.append(word3);

    /*tuple<int,QString,int> word1(1, QString("rhino"), 22);
    tuple<int,QString,int> word2(2, QString("tiger"), 15);
    tuple<int,QString,int> word3(3, QString("cupcake"), 11);

    wordFreqData.append(word1);
    wordFreqData.append(word2);
    wordFreqData.append(word3);
    */
}
