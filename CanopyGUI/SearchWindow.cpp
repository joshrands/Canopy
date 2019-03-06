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

    EmailData sample2;
    sample2.senderAddress = QString("wkuhr@mines.edu");
    sample2.receiverAddress = QString("shsaleh@mines.edu");
    sample2.subjectLine = QString("Interested in your turtles");
    sample2.dateTime = QDateTime(QDate(2019, 3, 1)), QTime(11, 48);
    this->emailData.append(sample2);

    populateEmailHeaders();
}

void SearchWindow::populateEmailHeaders()
{
    ui->emailHeaderList->widget()->setLayout(new QVBoxLayout());

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

//            QHBoxLayout* layout = new QHBoxLayout();
//            layout->setParent(ui->emailHeaderList);
 //           QFrame* frame = new QFrame();

//            ui->emailHeaderList->widget()->layout()->addWidget(frame);//->addScrollBarWidget(layout);
            // create new frame
  //          QFrame frame;
/*            frame.setParent(ui->emailFrame);
            frame.setFixedWidth(750);
            frame.setFixedHeight(50);
*/
            QLabel* emailLabel = new QLabel();
            emailLabel->setText(emailLabelText);
            ui->emailHeaderList->widget()->layout()->addWidget(emailLabel);
            //            ui->emailHeaderList->addScrollBarWidget(emailLabel);

//            layout->addWidget(emailLabel);
   //         this->emailFrames.append(frame);
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

}
