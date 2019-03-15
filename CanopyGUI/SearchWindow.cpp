#include "SearchWindow.h"
#include "WelcomeWindow.h"

#include "ui_SearchWindow.h"

#include <QDesktopWidget>
#include <QtAlgorithms>
#include <QFile>

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
    ui->dateLabel->setText(QDate::currentDate().toString(QString("MMMM d yyyy")));

    qDebug() << this->filePath;
    QFile file(this->filePath);

    if (file.exists())
    {
        qDebug() << "File size: " << file.size()/1000000000.0;
        ui->fileSizeLabel->setText(QString::number(file.size()/1000000000.0) + QString(" GB"));

        file.close();

        // parse input file
        this->emailData = parseEmailWarrant(this->filePath);
        this->displayEmails = emailData;

        ui->emailCountLabel->setText(QString::number(emailData.size()));

        // set up email header list scroll area
        ui->emailHeaderList->widget()->setLayout(new QVBoxLayout());
        ui->emailHeaderList->widget()->layout()->setAlignment(Qt::AlignTop);

        ui->freqCountScrollArea->widget()->setLayout(new QVBoxLayout());
        ui->freqCountScrollArea->widget()->layout()->setAlignment(Qt::AlignTop);

        populateEmailHeaders();

        getWordFrequency();
        populateWordFreq();

        // fill start and end date fields
        int i = 0;
        while (!displayEmails.at(i).dateTime.isValid())
            i++;
        ui->endDate->setDateTime(displayEmails.at(i).dateTime);

        i = displayEmails.length() - 1;
        while (!displayEmails.at(i).dateTime.isValid())
            i--;

        ui->startDate->setDateTime(displayEmails.at(i).dateTime);
    }
}

void SearchWindow::populateEmailHeaders()
{
    // delete existing emails
    for (int i = 0; i < this->emailFrames.length(); i++)
    {
        delete emailFrames.at(i);
    }

    this->emailFrames.clear();

    // put emails in chronological order
    sortDisplayEmails();

    QList<EmailData> validEmails;
    for (int i = 0; i < this->displayEmails.length(); i++)
    {
        EmailData email = this->displayEmails.at(i);

        // should we display this email?
        bool displayEmail = false;

        if (email.senderAddress == this->userEmail && outBtnState)
            displayEmail = true; // outbound enabled
        else if (email.receiverAddress == this->userEmail && inBtnState)
            displayEmail = true; // inbound enabled

        // display email in GUI
        if (displayEmail)
        {
            validEmails.append(displayEmails.at(i));

            QString emailLabelText;
            if (email.senderAddress == this->userEmail)
            {
                emailLabelText = QString("To: ");

                if (email.receiverAddress.length() <= 27)
                    emailLabelText = emailLabelText + email.receiverAddress;
                else
                    emailLabelText = emailLabelText + email.receiverAddress.left(24) + QString("...");
            }
            else
            {
                emailLabelText = QString("From: ");

                if (email.senderAddress.length() <= 27)
                    emailLabelText = emailLabelText + email.senderAddress;
                else
                    emailLabelText = emailLabelText + email.senderAddress.left(24) + QString("...");
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

            if (email.subjectLine.length() <= 30)
                subjectLabel->setText(email.subjectLine);
            else
                subjectLabel->setText(email.subjectLine.left(27) + QString("..."));

            subjectLabel->setAlignment(Qt::AlignCenter);
            subjectLabel->setAlignment(Qt::AlignTop);

            QLabel* dateLabel = new QLabel();
            dateLabel->setText(email.dateTime.toString());//email.dateTime.date().toString());
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

//    getWordFrequency();
//    populateWordFreq();
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

    this->getFilterInput();
    this->applyEmailFilters();

    this->populateEmailHeaders();
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
    // delete existing emails
    for (int i = 0; i < this->wordFreqFrames.length(); i++)
    {
        delete wordFreqFrames.at(i);
    }
    this->wordFreqFrames.clear();

    // populate gui based off information from getWordFrequency
    for (int i = 0; i < wordFreqDisplay.size(); i++)
    {
        WordFreq word = wordFreqDisplay.at(i);

//        qDebug() << word.word;
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
        frame->setFixedWidth(250);

        ui->freqCountScrollArea->widget()->layout()->addWidget(frame);
        wordFreqFrames.append(frame);
    }
}

void SearchWindow::applyEmailFilters()
{
     qDebug() << "Applying email filters";

     // call data analytics functions on email content
    int n = emailData.size();

    QList<EmailData> validEmails;
    for (int i = 0; i < n; i++)
    {
        // make sure email is within date range
        EmailData email = emailData.at(i);
        bool valid = true;

        if (!(email.dateTime >= startDateFilter && email.dateTime < endDateFilter))
            valid = false;

        if (valid)
            validEmails.append(email);
    }

    displayEmails = validEmails;
}

void SearchWindow::getWordFrequency()
{
    qDebug() << "Getting word count from input file";
    // call Canopy Data functions for word frequency on all email content

    // super inefficient method for getting word frequencies
    QList<WordFreq> wordCounts;
    QList<QString> words;

//    QFile file(this->filePath);

//    QTextStream in(&file);

    for (int i = 0; i < emailData.length(); i++)
    {
        // get data from content
        EmailData email = emailData.at(i);
//        QString data = "test";

        // add email addresses to word count
        if (email.senderAddress != userEmail)
        {
            if (words.contains(email.senderAddress))
            {
                // increment existing
                int index = words.indexOf(email.senderAddress);
                wordCounts[index].count = wordCounts.at(index).count + 1;
            }
            else
            {
                WordFreq word;
                word.count = 1;
                word.word = email.senderAddress;

                wordCounts.append(word);
                words.append(email.senderAddress);
            }
        }

        if (email.receiverAddress != userEmail)
        {
            if (words.contains(email.receiverAddress))
            {
                // increment existing
                int index = words.indexOf(email.receiverAddress);
                wordCounts[index].count = wordCounts.at(index).count + 1;
            }
            else
            {
                WordFreq word;
                word.count = 1;
                word.word = email.receiverAddress;

                wordCounts.append(word);
                words.append(email.receiverAddress);
            }
        }
        // run word frequency count on email content
        // TODO: Call TextAnalysis on this email content
        // getWordFreq(line, &wordCounts, &words);
        QFile file(email.parentFileName);

        if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            for (int i = 0; i < email.textLocation; i++)
            {
                in.readLine();
            }

            QString line;
            line = in.readLine();

            for (int i = 0; i < email.textLength; i++)
            {
                line = in.readLine();

                QString text = line;
                while (line.length() >= 76)
                {
                    if (text == line)
                    {
                        text = line.left(75);
                    }
                    else
                    {
                        text = text + line.left(75);
                    }
                    line = in.readLine();
                }

                getWordFreq(text, &wordCounts, &words);
            }

        }
        file.close();
    }

//    file.close();

    qSort(wordCounts);
    int i = 0;
    while (i < wordCounts.size() && wordCounts[i].count >= 10)
    {
        wordCounts[i].rank = i + 1;
        wordFreqData.append(wordCounts[i]);

        i++;
    }

    wordCounts.clear();
    words.clear();

    /*
    QList<int> values = wordCounts.values();
    qSort(values);

    std::reverse(values.begin(), values.end());

    for (int i = 0; i < values.size(); i++)
    {
        WordFreq word(i + 1, wordCounts.key(values.at(i)), values.at(i));
        wordFreqData.append(word);
    }
    */
/*
    WordFreq word1(1, QString("rhino"), 22);
    WordFreq word2(2, QString("tiger"), 15);
    WordFreq word3(3, QString("cupcake"), 11);

    wordFreqData.append(word1);
    wordFreqData.append(word2);
    wordFreqData.append(word3);
*/
    wordFreqDisplay = wordFreqData;
}

void SearchWindow::getFilterInput()
{
    // get filter input from user
    qDebug() << "Adding filter input";

    startDateFilter = ui->startDate->dateTime();
    endDateFilter = ui->endDate->dateTime();
}

void SearchWindow::on_addKeywordButton_clicked()
{
    QString key = ui->keywordInput->text();
    if (key != QString(""))
    {
        if (!keywordFilters.contains(key))
        {
            keywordFilters.append(key);
            // create frame

            QLabel* label = new QLabel();
            label->setText(key);

            // TODO: Get this to be on same row
            ui->keywordBank->layout()->addWidget(label);
        }
    }
}

bool SearchWindow::emailLessThan(const EmailData* d1, const EmailData* d2)
{
    return (d1->dateTime < d2->dateTime);
}

void SearchWindow::sortDisplayEmails()
{
//    qSort(displayEmails.begin(), displayEmails.end(), emailLessThan);
    qSort(displayEmails);
}

void SearchWindow::on_wordFreqFilter_textChanged(const QString &arg1)
{
   //qDebug() << arg1;
   wordFreqDisplay.clear();

   for (int i = 0; i < wordFreqData.length(); i++)
   {
        if (wordFreqData.at(i).word.contains(arg1))
            wordFreqDisplay.append(wordFreqData.at(i));
   }

   populateWordFreq();
}
