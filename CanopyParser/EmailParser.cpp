#include "EmailParser.h"
#include <QDebug>
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QStringRef>
#include <QString>

using namespace std;

QList<EmailData> parseEmailWarrant(QString fileName)
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
        return parseMBOX(fileName);
        break;

    default:
        return QList<EmailData>();
        break;
    }
}

void parseEmailString(QString line, QString* address)
{
//    qDebug() << line;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '<')
        {
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
        }
    }
}

void parseMIMEHeader(EmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    //qDebug() << "Parsing MIME header";
    bool from = false;
    bool to = false;
    while (!line->isNull() && line->left(12) != QString("Content-Type"))
    {
        if (line->left(5) == "From:")
        {
            from = true;
            QString sender;
            parseEmailString(*line, &sender);
            email->senderAddress = sender;
        }
        else if (line->left(3) == "To:")
        {
            to = true;
            QString receiver;
            parseEmailString(*line, &receiver);
            email->receiverAddress = receiver;
        }
        else if (line->left(8) == "Subject:")
        {
            QString subject = line->mid(8, line->length() - 8);
            email->subjectLine = subject;
        }
        else if (line->left(5) == "Date:")
        {
            QString date = line->mid(5, line->length() - 5);
            email->dateString = date;
            //            email->dateTime.fromString(date);
        }

        *line = in->readLine();
        *fileLoc = *fileLoc + 1;
    }

    if (!(to && from))
    {
        // weird format

    }
    //qDebug() << *line;
    //qDebug() << *fileLoc;
}

void parseMIMEContent(EmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
  //  QString content = "";
    while (!line->isNull() && line->left(10) != QString("X-GM-THRID"))
    {
        *line = in->readLine();
        *fileLoc = *fileLoc + 1;
    }
//    qDebug() << content;
}

QList<EmailData> parseMBOX(QString fileName)
{
    // parse mbox and create EmailData objects
    QList<EmailData> emails;

    // open the file
//    string file = "test.eml";
 //   ifstream inFile(fileName.toStdWString());//fileName.toStdString());
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
        EmailData email;
        email.subjectLine = QString("NO SUBJECT");
        email.senderAddress = QString("NO ADDRESS");
        email.receiverAddress = QString("NO ADDRESS");
        email.dateTime.setDate(QDate(2000, 0, 0));

        parseMIMEHeader(&email, &in, &line, &fileLoc);
        //line = in.readLine();
        //qDebug() << line;
        parseMIMEContent(&email, &in, &line, &fileLoc);
        //qDebug() << line;
        line = in.readLine();
        fileLoc++;

        emails.push_back(email);
    }

    /*QString line = in.readLine();
    while (!line.isNull()) {
        qDebug() << line;
//        line = in.readLine();
    }
*/
    /*
    string line;
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            qDebug() << line;
        }
    }

    // read the header information from file

    // read content types
*/

    return emails;
}
