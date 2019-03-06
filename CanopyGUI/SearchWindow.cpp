#include "SearchWindow.h"
#include "WelcomeWindow.h"

#include "ui_SearchWindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);

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

    // parse input file
    this->emailData = parseEmailWarrant(this->fileName);

    // REMOVE IN RELEASE
    // ADD SAMPLE DATA
    // This is Werner's inbox
    // TODO: Add user email in WelcomeWindow
    this->userEmail = QString("wkuhr@mines.edu");

    EmailData sample1;
    sample1.senderAddress = QString("shsaleh@mines.edu");
    sample1.receiverAddress = QString("wkuhr@mines.edu");
    sample1.subjectLine = QString("Interested in your turtles");
    sample1.dateTime = QDateTime(QDate(2019, 3, 1)), QTime(10, 30);
    this->emailData.append(sample1);

    EmailData sample2;
    sample2.senderAddress = QString("wkuhr@mines.edu");
    sample2.receiverAddress = QString("shsaleh@mines.edu");
    sample2.subjectLine = QString("Interested in your turtles");
    sample2.dateTime = QDateTime(QDate(2019, 3, 1)), QTime(11, 48);
    this->emailData.append(sample2);

    // set up email header list scroll area
    ui->emailHeaderList->widget()->setLayout(new QVBoxLayout());
    ui->emailHeaderList->widget()->layout()->setAlignment(Qt::AlignTop);
    populateEmailHeaders();
}

void SearchWindow::populateEmailHeaders()
{
    for (int i = 0; i < this->emailFrames.length(); i++)
    {
        delete emailFrames.at(i);
    }

    this->emailFrames.clear();

    for (int i = 0; i < this->emailData.length(); i++)
    {
        EmailData email = this->emailData.at(i);
        qDebug() << email.senderAddress;

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
                emailLabelText = email.senderAddress;

            QHBoxLayout* layout = new QHBoxLayout();

            // create frame and set horizontal layout
            QFrame* frame = new QFrame();
            frame->setLayout(layout);

            QLabel* emailLabel = new QLabel();
            emailLabel->setText(emailLabelText);
            emailLabel->setAlignment(Qt::AlignLeft);

            QLabel* subjectLabel = new QLabel();
            subjectLabel->setText(email.subjectLine);
            subjectLabel->setAlignment(Qt::AlignCenter);
            subjectLabel->setAlignment(Qt::AlignTop);

            QLabel* dateLabel = new QLabel();
            dateLabel->setText(email.dateTime.date().toString());
            dateLabel->setAlignment(Qt::AlignRight);
            dateLabel->setAlignment(Qt::AlignTop);

            frame->layout()->addWidget(emailLabel);
            frame->layout()->addWidget(subjectLabel);
            frame->layout()->addWidget(dateLabel);
            frame->setFixedHeight(40);
            frame->setFixedWidth(750);

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
