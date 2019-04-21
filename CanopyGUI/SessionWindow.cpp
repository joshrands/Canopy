#include "AddDataWindow.h"
#include "ui_SessionWindow.h"

#include <QDesktopWidget>
#include <QStringList>
#include <QDebug>

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

    displayNewContent();
}

void SessionWindow::displayNewContent()
{
    qDebug() << "Displaying new content...";
}

