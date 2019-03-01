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
