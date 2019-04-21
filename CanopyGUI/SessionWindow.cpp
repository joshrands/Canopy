#include "AddDataWindow.h"
#include "ui_SessionWindow.h"

#include <QDesktopWidget>
#include <QStringList>
#include <QDebug>
#include <QPushButton>

SessionWindow::SessionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SessionWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    // sort by options
    QStringList sortBy = QStringList() << "Newest to Oldest" <<
                                          "Oldest to Newest" <<
                                          "Priority" <<
                                          "Alphabetical";

    ui->sortComboBox->addItems(sortBy);
}

SessionWindow::~SessionWindow()
{
    delete ui;
}

void SessionWindow::on_addDataButton_clicked()
{
    // show add data window
    AddDataWindow* win = new AddDataWindow();

    win->setCreateSession(false);
    win->setSessionWindow(this);

    win->show();
    this->hide();
}

void SessionWindow::addData(Data *data)
{
    qDebug() << "Adding data to session...";

    this->activeData = data;
    this->data.append(data);
    this->activeDataName = data->getDataName();

    // make new button
    ui->contentTabs->layout()->setAlignment(Qt::AlignLeft);
    data->tabButton->setText(data->getDataName());
    ui->contentTabs->layout()->addWidget(data->tabButton);

    data->createWindow();
    ui->contentFrame->layout()->addWidget(data->window);

    connect(data->tabButton, SIGNAL(clicked(bool)), this, SLOT(tabButtonPressed()));

    displayNewContent();
}

void SessionWindow::displayNewContent()
{
    qDebug() << "Displaying new content...";

    ui->suspectNameLabel->setText(activeData->getSuspectName());
    ui->dataNameLabel->setText(activeData->getDataName());

    this->dataFilePath = activeData->getDataPath();

    // change button color to gray
    for (int i = 0; i < this->data.length(); i++)
    {
        if (data.at(i)->getDataName() != activeDataName)
        {
            data.at(i)->tabButton->setStyleSheet("background-color: white;");
            data.at(i)->window->hide();
        }
        else
        {
            data.at(i)->tabButton->setStyleSheet("background-color: gray;");
            data.at(i)->window->show();
        }
    }
}

void SessionWindow::tabButtonPressed()
{
    qDebug() << "Pressed";
    DataTabButton *btn = (DataTabButton*)QObject::sender();
    this->activeData = btn->data;
    this->activeDataName = btn->data->getDataName();

    displayNewContent();
}

