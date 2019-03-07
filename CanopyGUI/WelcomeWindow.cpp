#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"
#include <QDesktopWidget>

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    /**** REMOVE THIS LINE IN RELEASE VERSION ****/
    ui->evaluateButton->setEnabled(true);

    ui->fileFrame->setStyleSheet("background-color: white;");
    ui->browseButton->setStyleSheet("background-color: pale gray;");

    this->currentDirectory = QString("/home");
    this->fileName = QString("");
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_browseButton_clicked()
{
    if ((this->fileName = QFileDialog::getOpenFileName(this, tr("Open File"),currentDirectory,tr("Images (*.txt *.html *.eml *.mbox)"))) != "")
    {
        // assign the full path
        this->filePath = this->fileName;

        this->fileName = this->getFileNameFromPath(this->fileName);
        ui->fileNameLabel->setText(this->fileName);
    }
    else
    {
        ui->fileNameLabel->setText("No file selected");
        this->fileName = QString("");
    }

    this->checkEvaluate();
}

void WelcomeWindow::checkEvaluate()
{
    if (this->fileName != QString("") && ui->suspectNameField->text() != QString("") && ui->warrantNumberField->text() != QString(""))
    {
        ui->evaluateButton->setEnabled(true);
    }
    else
    {
        /**** SET THIS FALSE ON RELEASE ****/
        ui->evaluateButton->setEnabled(true);
    }
}

void WelcomeWindow::on_suspectNameField_editingFinished()
{
    this->checkEvaluate();
}

void WelcomeWindow::on_warrantNumberField_editingFinished()
{
    this->checkEvaluate();
}

void WelcomeWindow::on_evaluateButton_clicked()
{
    this->getFieldValues(); // get variable valeus from fields

    SearchWindow* win = new SearchWindow(this);
    win->setFileName(this->fileName);
    win->setSuspectName(this->suspectName);
    win->setWarrantNumber(this->warrantNumber);
    win->setFilePath(this->filePath);

    // emails are parsed in initialize function
    win->initialize();
    win->show();

    hide();
}

QString WelcomeWindow::getFileNameFromPath(QString path)
{
    QStringList list = path.split("/");

    return list.at(list.length() - 1);
}

void WelcomeWindow::getFieldValues()
{
    this->fileName = ui->fileNameLabel->text();
    this->suspectName = ui->suspectNameField->text();
    this->warrantNumber = ui->warrantNumberField->text().toInt();
}

void WelcomeWindow::initialize()
{
    ui->fileNameLabel->setText(this->fileName);
    ui->suspectNameField->setText(this->suspectName);
    ui->warrantNumberField->setText(QString::number(this->warrantNumber));
}
