#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    /**** REMOVE THIS LINE IN RELEASE VERSION ****/
    ui->evaluateButton->setEnabled(false);

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
        ui->evaluateButton->setEnabled(false);
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
