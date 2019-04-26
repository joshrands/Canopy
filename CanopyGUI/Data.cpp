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
    //window->setSessionPath(this->sessionPath);
    //window->setContentName(this->dataName);
    window->initializeDir(this->sessionPath, this->dataName);
    window->parseDataFile(this->dataPath);
}

QStringList splitCanLine(QString line)
{

}

EmailCan* getEmailCan(QTextStream* in, int* fileLoc, QString* line)
{
    EmailCan* email = new EmailCan;

    //*line = in->readLine();
    qDebug() << *line;
    QStringList canData = line->split(",");

    qDebug() << canData.at(0);
    int numLines = canData.at(0).toInt();

    for (int i = 1; i <= numLines; i++)
    {
        *line = in->readLine();
        canData << line->split(",");
    }

    qDebug() << canData.length();
    for (int i = 0; i < canData.length(); i++)
        qDebug() << canData.at(i);
}

void EmailData::getCanData(int start, int num)
{
    qDebug() << "Getting can data from " << this->dataName;
    qDebug() << "Loading emails " << start << " to " << start + num;

    // parse can file and create EmailCan objects
    // starting at can *start* and loading *num* email headers

    QString path = this->getSessionPath() + QString("/session/") + this->dataName + QString("/") + this->dataName + QString(".can");
    qDebug() << path;
    QFile canFile(path);

    if (!canFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "ERROR opening can file";
    }
    else
    {
        QTextStream can(&canFile);
        QString line = can.readLine();
        int fileLoc = 0;
        int count = 0;

        // get to start page
        while (!line.isNull() && count != start)
        {
            // iterate
        }

        // read num emails
        qDebug() << line;
        while (!line.isNull() && count != start + num)
        {
//            qDebug() << line;
//            line = can.readLine();
//            fileLoc++;
            EmailCan* email = getEmailCan(&can, &fileLoc, &line);

            line = can.readLine();
            count++;
        }
    }

}

void HtmlData::createWindow()
{
    window = new HtmlContentWindow();
    window->initializeDir(this->sessionPath, this->dataName);
    window->parseDataFile(this->dataPath);
}

void HtmlData::getCanData(int start, int num)
{

}

