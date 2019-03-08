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

    }
}

void parseMIMEHeader(EmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    qDebug() << "Parsing MIME header";
    while (!line->isNull() && line->left(12) != QString("Content-Type"))
    {
        if (line->left(5) == "From:")
        {
            QString sender;
            parseEmailString(*line, &sender);
            email->senderAddress = sender;
        }
        else if (line->left(3) == "To:")
        {
            QString receiver;
            parseEmailString(*line, &receiver);
            email->receiverAddress = receiver;
        }
        //        qDebug() << line->left(12);
/*        if (line->left(5) == "From:")
        {
            //qDebug() << *line;
            // parse email
            for (int i = 0; i < line->length(); i++)
            {
                if (line->at(i) == '<')
                {
                    QString sender = line->mid(i + 1, line->length() - i - 2);
                    qDebug() << sender;
                    email->senderAddress = sender;
                    i = line->length();
                }
                else if (line->at(i) == '[')
                {
                    // mailto syntax
                }
            }
        }

        if (line->left(3) == "To:")
        {
            //qDebug() << *line;
            // parse email
            for (int i = 0; i < line->length(); i++)
            {
                if (line->at(i) == '<')
                {
                    QString receiver = line->mid(i + 1, line->length() - i - 2);
                    qDebug() << receiver;
                    email->receiverAddress = receiver;
                    i = line->length();
                }
                else if (line->at(i) == '[')
                {
                    // mailto syntax
                }
            }
        }
        */
        *line = in->readLine();
        *fileLoc = *fileLoc + 1;
    }
//    qDebug() << *line;
}

void parseMIMEContent(EmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    while (!line->isNull() && *line != QString("X-GM-THRID"))
    {
        *line = in->readLine();
        *fileLoc++;
    }
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
    while (!line.isNull())
    {
        EmailData email;
        email.subjectLine = QString("NO SUBJECT");
        email.senderAddress = QString("NO ADDRESS");
        email.receiverAddress = QString("NO ADDRESS");
        email.dateTime.setDate(QDate(2000, 0, 0));

        parseMIMEHeader(&email, &in, &line, &fileLoc);
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
