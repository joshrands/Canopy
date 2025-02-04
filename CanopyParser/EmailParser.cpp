#include "EmailParser.h"
#include <QDebug>
#include <fstream>
#include <string>
#include <QFile>
#include <QStringRef>
#include <QString>
#include <QTime>
#include <QMap>

using namespace std;

QList<LocalEmailData> parseEmailWarrant(QString fileName)
{
    qDebug() << "Parsing email warrant";
    EmailFileType type;

    // get file type
    int index = fileName.lastIndexOf('.');

    QStringRef ext = fileName.midRef(index + 1);

    if (ext == QString("mbox"))
        type = MBOX;
    else if (ext == QString("eml"))
        type = EML;
    else
        type = NONE;

    switch (type)
    {
    case MBOX:
        qDebug() << "Parsing MBOX";
 //       return parseMBOX(fileName);
        break;

    default:
        return QList<LocalEmailData>();
        break;
    }
}

/*
void parseEmailString(QString line, QString* address)
{
    bool found = false;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '<')
        {
            found = true;
            // find '>', if not end get next email
            int start = i + 1;
            while (line.at(i) != '>' && i < line.length() - 1)
                i++;

            *address = *address + line.mid(start, i - start);
            if (i != line.length() - 1)
                *address += ", ";
        }
        else if (line.at(i) == '[')
        {
            //qDebug() << line;
            // UPDATE: This shouldn't happen if parsing is done right
        }
    }

    if (!found)
    {
        // email not in address book, follows different format
        *address = line.right(line.length() - 4);
    }
}

void parseMIMEHeader(LocalEmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    bool from = false;
    bool to = false;
//    qDebug() << "Parsing header at " << *fileLoc;
    while (!line->isNull() && line->left(12) != QString("Content-Type"))
    {
//        qDebug() << *line;

        if (line->left(5) == "From:")
        {
            from = true;
            QString sender;
            parseEmailString(*line, &sender);
            email->senderAddress = sender;
        }
        else if (line->left(3) == "To:")
        {
            //qDebug() << *line;
            to = true;
            QString receiver;
            parseEmailString(*line, &receiver);
            email->receiverAddress = receiver;
        }
        else if (line->left(8) == "Subject:")
        {
            QString subject = line->mid(9, line->length() - 8);
            email->subjectLine = subject;
        }
        else if (line->left(5) == "Date:")
        {
            QString date = line->mid(6, line->length() - 5);
            date = date.left(date.length() - 6);
            email->dateString = date;

            email->dateTime = parseMIMEDateString(date);
        }

        *line = in->readLine();
        *fileLoc = *fileLoc + 1;
    }

//    qDebug() << "Parsed from " << email->senderAddress;
//    qDebug() << "To: " << email->receiverAddress;
//    qDebug() << *fileLoc;

    if (!(to && from))
    {
        // weird format
        qDebug() << "Unknown format at line: " << *fileLoc;
    }
}

void parseMIMEContent(LocalEmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    QString previousLine = QString("");

    email->textLocation = 0;
    email->textLength = 0;

    while (!line->isNull() && line->left(10) != QString("X-GM-THRID"))
    {
//        qDebug() << previousLine << *fileLoc << ": " << *line;

        if (line->mid(14,10) == QString("text/plain"))
        {
//            qDebug() << "text/plain: " << *fileLoc << ": " << previousLine;
            email->textLocation = *fileLoc;

            // get length
            QString temp;
            while (!line->isNull() && *line != previousLine && line->left(10) != QString("X-GM-THRID"))
            {
                temp = *line;
                *line = in->readLine();
                *fileLoc = *fileLoc + 1;
            }

            previousLine = temp;

//            qDebug() << "End: " << *fileLoc;
            email->textLength = *fileLoc - email->textLocation;
//            qDebug() << email->textLength;
        }
        else if (line->mid(14, 9) == QString("text/html"))
        {
//            qDebug() << "text/html: " << *fileLoc << ": " << previousLine;
            email->htmlLocation = *fileLoc;

            //qDebug() << previousLine;
            // get length
            *line = in->readLine();
            *fileLoc = *fileLoc + 1;

            QString temp;
            while (!line->isNull() && line->left(previousLine.length()) != previousLine && line->left(10) != QString("X-GM-THRID"))
            {
                temp = *line;
                *line = in->readLine();
                *fileLoc = *fileLoc + 1;
            }
            previousLine = temp;

//            qDebug() << "HTML End: " << *fileLoc;
            email->htmlLength = *fileLoc - email->htmlLocation;
//            qDebug() << email->htmlLength;
        }
        else
        {
            previousLine = *line;
            *line = in->readLine();
            *fileLoc = *fileLoc + 1;
        }
    }
}

QList<LocalEmailData> parseMBOX(QString fileName)
{
    // parse mbox and create EmailData objects
    QList<LocalEmailData> emails;

    // open the file
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file: " << fileName;
        return emails;
    }

    QTextStream in(&file);

    QString line = in.readLine();
    int fileLoc = 0;
    qDebug() << "Opening file";
    while (!line.isNull())
    {
        LocalEmailData email;
        email.parentFileName = fileName;
        email.subjectLine = QString("NO SUBJECT");
        email.senderAddress = QString("NO ADDRESS");
        email.receiverAddress = QString("NO ADDRESS");
        email.dateTime.setDate(QDate(2000, 0, 0));

        parseMIMEHeader(&email, &in, &line, &fileLoc);
        parseMIMEContent(&email, &in, &line, &fileLoc);

        line = in.readLine();
        fileLoc++;

        emails.push_back(email);
    }

    file.close();

    return emails;
}

QDateTime parseMIMEDateString(QString dateString)
{
    QDateTime date;
    int d, m, y;

    int i = 0;

    // get date
    if (dateString.at(i).isLetter())
        i += 5;

    int start = i;
    while (dateString.at(i) != ' ')
        i++;

    d = dateString.mid(start, i - start).toInt();

    // get month
    i+=1; // move past empty space
    start = i;
    while (dateString.at(i) != ' ')
        i++;

    m = getMonthIndex(dateString.mid(start, i - start));

    // get year
    i+=1; // move past empty space
    start = i;
    while (dateString.at(i) != ' ')
        i++;

    y = dateString.mid(start, i - start).toInt(); // get only last 2 digits

    // get time
    i+=1; // move past empty space
    int h = dateString.mid(i, 2).toInt();
    i+=3;
    int min = dateString.mid(i, 2).toInt();
    i+=3;
    int s = dateString.mid(i, 2).toInt();

    date.setDate(QDate(y, m, d));
    date.setTime(QTime(h, min, s));

    return date;
}

int getMonthIndex(QString month)
{
    QMap<QString,int> months;

    months.insert("Jan", 1);
    months.insert("Feb", 2);
    months.insert("Mar", 3);
    months.insert("Apr", 4);
    months.insert("May", 5);
    months.insert("Jun", 6);
    months.insert("Jul", 7);
    months.insert("Aug", 8);
    months.insert("Sep", 9);
    months.insert("Oct", 10);
    months.insert("Nov", 11);
    months.insert("Dec", 12);

    return months.value(month);
}
*/
