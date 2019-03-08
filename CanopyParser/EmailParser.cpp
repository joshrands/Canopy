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

void parseMIMEHeader(EmailData* email, QTextStream* in, QString* line, int* fileLoc)
{
    while (!line->isNull() && line->left(12) != QString("Content-Type"))
    {
//        qDebug() << line->left(12);
        if (line->left(5) == "From:")
            qDebug() << *line;

        *line = in->readLine();
        *fileLoc++;
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
    EmailData email;

    QString line = in.readLine();
    int fileLoc = 0;
    while (!line.isNull())
    {
        parseMIMEHeader(&email, &in, &line, &fileLoc);
        //qDebug() << line;
        line = in.readLine();
        fileLoc++;
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
