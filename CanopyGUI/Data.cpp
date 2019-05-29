#include "Data.h"

// REMEMBER TO ADD WHAT TYPE OF FILE IN BROWSE BUTTON PROCESSING
// CREATE NEW CONTENT DISPLAY IF CANT USE EXISTING
QStringList Data::types = (QStringList() << "Gmail" << "Facebook");

Data::Data(QWidget* parent) : QWidget(parent)
{
    // configure button details
    this->tabButton = new DataTabButton();
    this->tabButton->window = window;
    this->tabButton->setText(this->dataName);
    this->tabButton->data = this;

    signalMapper = new QSignalMapper(this->window);
}

Data::~Data()
{

}

EmailData::EmailData(QWidget *parent) : Data(parent)
{
    qDebug() << "Creating email data";
}

//EmailData::~EmailData()

void EmailData::filterEmails(EmailFilter* filter)
{
    qDebug() << "Filtering emails";

    EmailContentWindow* win = ((EmailContentWindow*)this->window);

    if (filter->showReceiver)
    {
        // show receiver
        for (int i = 0; i < win->headerButtons.size(); i++)
        {
            win->headerButtons.at(i)->displayReceiver();
        }
    }
    else if (filter->showSender)
    {
        // show sender
        for (int i = 0; i < win->headerButtons.size(); i++)
        {
            win->headerButtons.at(i)->displaySender();
        }
    }
}

void EmailData::createWindow()
{
    window = new EmailContentWindow();

    qDebug() << "Email content window created";

    // catch page SIGNALS
//    this->window->connect(this->window, SIGNAL(nextPageSignal()), this, SLOT(nextPage()));
    ((EmailContentWindow*)this->window)->connect(((EmailContentWindow*)this->window)->nextPageButton, SIGNAL(clicked(bool)), this, SLOT(nextPage()));
    ((EmailContentWindow*)this->window)->connect(((EmailContentWindow*)this->window)->prevPageButton, SIGNAL(clicked(bool)), this, SLOT(prevPage()));

    ((EmailContentWindow*)this->window)->connect(((EmailContentWindow*)this->window)->sentButton, SIGNAL(clicked(bool)), this, SLOT(filterBySender()));
    ((EmailContentWindow*)this->window)->connect(((EmailContentWindow*)this->window)->receiveButton, SIGNAL(clicked(bool)), this, SLOT(filterByReceiver()));

    window->initializeDir(this->sessionPath, this->dataName);
    window->parseDataFile(this->dataPath);
}

void EmailData::filterByReceiver()
{
    qDebug() << "Filtering emails by receiver";

    ((EmailContentWindow*)this->window)->sentButton->setDepressed();
    ((EmailContentWindow*)this->window)->receiveButton->setPressed();

    EmailFilter filter;
    filter.showReceiver = true;
    filter.showSender = false;

    this->filterEmails(&filter);
}

void EmailData::filterBySender()
{
    qDebug() << "Filtering emails by sender";

    ((EmailContentWindow*)this->window)->sentButton->setPressed();
    ((EmailContentWindow*)this->window)->receiveButton->setDepressed();

    EmailFilter filter;
    filter.showReceiver = false;
    filter.showSender = true;

    this->filterEmails(&filter);
}

void EmailData::nextPage()
{
    qDebug() << "NEXT";
    EmailContentWindow* win = ((EmailContentWindow*)this->window);

    if (!win->atMaxPage)
    {
        win->page++;
        // display new CAN data
        this->getCanData(win->page * win->EMAILS_PER_PAGE, win->EMAILS_PER_PAGE);
    }
    else
        qDebug() << "At max page";

    qDebug() << "Page: " << win->page;
}

void EmailData::prevPage()
{
    qDebug() << "PREV";
    EmailContentWindow* win = ((EmailContentWindow*)this->window);

    if (win->page > 0)
    {
        win->page--;

        this->getCanData(win->page * win->EMAILS_PER_PAGE, win->EMAILS_PER_PAGE);
    }

    qDebug() << "Page: " << win->page;
}

QStringList splitCanData(QTextStream* in, QString* line)
{
    // get length
    int i = 0;
    while (line->at(i) != ',')
        i++;

    int numLines = line->left(i).toInt();

    QStringList data;
    data << QString::number(numLines);

    for (i = 0; i < numLines; i++)
    {
        *line = *line + in->readLine();
    }

    qDebug() << *line;
    for (int i = 0; i < line->length(); i++)
    {
        // get string stuff
        int start = i;
//        qDebug() << line->mid(i, 1);
//        qDebug() << QString("\"");
//        if (QString(line->at(i)) == QString("\\"))
        if (line->mid(i, 2) == QString("\\\""))
        {
//            qDebug() << "Special processing";
            // requires special processing
            start = ++i;
            while (line->mid(i, 2) != QString("\\\""))
                i++;
            i+=2;

            QString column = line->mid(start + 1, i-start-3);
            data << column;
        }
        else
        {
            while (line->at(i) != ',' && i < line->length() - 1)
                i++;

            QString column = line->mid(start, i-start);
            data << column;
        }
    }

    return data;
}

EmailCan* getEmailCan(QTextStream* in, int* fileLoc, QString* line)
{
    EmailCan* email = new EmailCan;

    QStringList canData = splitCanData(in, line);

//    for (int i = 0; i < canData.length(); i++)
//        qDebug() << canData.at(i);

    email->sender = canData.at(6);
    email->receiver = canData.at(7);
    email->subject = canData.at(9);
    email->date = canData.at(8);
    // TODO: Get datetime

    // get line number
    email->lineNum = canData.at(2).toInt();
//    qDebug() << email->lineNum;

    return email;
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

        // clear window
        for (int i = 0; i < ((EmailContentWindow*)this->window)->headerButtons.size(); i++)
        {
            delete ((EmailContentWindow*)this->window)->headerButtons.at(i);
        }
        ((EmailContentWindow*)this->window)->headerButtons.clear();


        // get to start page
        while (!line.isNull() && count != start)
        {
            // iterata
            qDebug() << "Data: " << line;
            // get number of lines
            int numCanLines = line.mid(0,1).toInt();//.Number_DecimalDigit;// - QChar('0');
            qDebug() << "Num: " << numCanLines;
            qDebug() << "Can: " << count;
            for (int i = 0; i < numCanLines; i++)
            {
                line = can.readLine();
                qDebug() << line;
            }
            line = can.readLine();
            count++;
            //            EmailCan* email = getEmailCan(&can, &fileLoc, &line);
        }

        // read num emails
        while (!line.isNull() && count != start + num)
        {
            qDebug() << "Line num: " << fileLoc;
            //            qDebug() << line;
//            line = can.readLine();
//            fileLoc++;
            EmailCan* email = getEmailCan(&can, &fileLoc, &line);
            // display email can
            EmailHeaderFrame* frame = new EmailHeaderFrame();

            QString sender(email->sender);
            QString receiver(email->receiver);
            QString header(email->subject);
            QString date(email->date);
            frame->setEmailData(count, sender, receiver, header, date);
            frame->displaySender();

            QString contentPath = this->sessionPath + "/session/working/" + this->dataName + ".txt";
            qDebug() << contentPath;
            int lineNum = email->lineNum;
            frame->setContentFileInfo(contentPath, lineNum);

            ((EmailContentWindow*)this->window)->addHeaderFrame(frame);

            delete email;

            // override clicked event
            this->window->connect(frame, SIGNAL(clicked()),
                                  signalMapper, SLOT(map()));

            // map this frame event to the EmailCan data
            signalMapper->setMapping(frame, count-start);

            this->window->connect(signalMapper, SIGNAL(mapped(int)), (EmailContentWindow*)this->window, SLOT(displayContent(int)));

            line = can.readLine();
            count++;
        }
        if (line.isNull())
            this->window->atMaxPage = true;
//        ((EmailContentWindow*)this->window)->page++;
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

