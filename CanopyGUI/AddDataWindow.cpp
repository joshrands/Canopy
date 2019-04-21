#include "AddDataWindow.h"
#include "ui_AddDataWindow.h"
#include "SessionWindow.h"
#include "CaseData.h"

#include <QDesktopWidget>
#include <QFileDialog>
#include <QDebug>

AddDataWindow::AddDataWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddDataWindow)
{
    ui->setupUi(this);

    populateProviderBox();

    // TODO: REMOVE THIS BEFORE DEPLOYMENT
    this->dataPath = "/home/josh/HunterArmstrong.mbox";
    ui->createSessionButton->setEnabled(true);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}

AddDataWindow::~AddDataWindow()
{
    delete ui;
}

void AddDataWindow::populateProviderBox()
{
    QStringList list = CaseData::types;//(QStringList() << "Gmail" << "Facebook");
    ui->providerComboxBox->addItems(list);
}

// browse for the data file for what you are viewing
void AddDataWindow::on_browseButton_clicked()
{
    // current directory
    QString currentDirectory = "/home";
    QString dataType = ui->providerComboxBox->currentText();

    // get type of data searching for
    if (dataType == "Gmail")
    {
        this->dataPath = QFileDialog::getOpenFileName(this, tr("Select Data File"),
                                                      currentDirectory,
                                                      tr("Warrant (*.mbox)"));
    }
    else if (dataType == "Facebook")
    {
        this->dataPath = QFileDialog::getExistingDirectory(this, tr("Select Top Level Folder"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    }

    qDebug() << this->dataPath;

    if (this->dataPath != QString(""))
    {
        QStringList list = this->dataPath.split("/");

        this->dataName = list.at(list.length() - 1);
        ui->fileNameLabel->setText(this->dataName);
    }
    else
    {
        ui->fileNameLabel->setText("No file selected");
        this->dataName = QString("");
    }

    // check if data is entered properly
    if (checkValidFields())
    {
        // enable button
        ui->createSessionButton->setEnabled(true);
    }
    else
    {
        ui->createSessionButton->setEnabled(false);
    }
}

bool AddDataWindow::checkValidFields()
{
    if (ui->suspectNameLineEdit->text() == QString(""))
        return false;
    if (this->dataPath == QString(""))
        return false;

    return true;
}

void AddDataWindow::on_createSessionButton_clicked()
{
    qDebug() << "Creating new session..." << endl;

    SessionWindow* session = new SessionWindow();

    session->show();
    this->close();
}

void AddDataWindow::setCreateSession(bool val)
{
    this->session = val;

    if (session)
    {
        ui->createSessionButton->setText(QString("Create Session"));
        ui->cancelButton->setEnabled(false);
    }
    else
    {
        ui->createSessionButton->setText(QString("Add Data"));
        ui->cancelButton->setEnabled(true);
    }
}

void AddDataWindow::on_cancelButton_clicked()
{
    qDebug() << "Canceling data add";
}
