#include "StartWindow.h"
#include "ui_StartWindow.h"
#include "AddDataWindow.h"

#include <QDesktopWidget>
#include <QFileDialog>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // center window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_newSessionButton_clicked()
{
    AddDataWindow* win = new AddDataWindow(this);

    hide();

    // prompt for session directory
    QString dir = QString("");
    while (dir == QString(""))
    {
        dir = QFileDialog::getExistingDirectory(this, tr("Select Location for New Session Directory"),
                                                 "/home/canopy",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
        // add error message if files
    }

    win->setSessionPath(dir);
    win->setCreateSession(true);
    win->show();
}
