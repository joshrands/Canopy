#include "Data.h"

// REMEMBER TO ADD WHAT TYPE OF FILE IN BROWSE BUTTON PROCESSING
// CREATE NEW CONTENT DISPLAY IF CANT USE EXISTING
QStringList Data::types = (QStringList() << "Gmail" << "Facebook");

Data::Data()
{
    // configure button details
    this->tabButton = new DataTabButton();
    this->tabButton->window = window;
    this->tabButton->setText(this->dataName);
    this->tabButton->data = this;
}

void EmailData::createWindow()
{
    window = new EmailContentWindow();
    window->parseDataFile(this->dataPath);
}

void HtmlData::createWindow()
{
    window = new HtmlContentWindow();
    window->parseDataFile(this->dataPath);
}

