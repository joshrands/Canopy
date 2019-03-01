#include "SearchWindow.h"
#include "ui_SearchWindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}
