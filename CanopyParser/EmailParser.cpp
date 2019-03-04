#include "EmailParser.h"
#include <QDebug>

QList<EmailData> parseEmailWarrant(QString fileName)
{
    EmailFileType type;

    // get file type
    int index = fileName.lastIndexOf('.');

    QStringRef ext = fileName.midRef(index + 1);


    switch (type)
    {
    case MBOX:
        return parseMBOX(fileName);
        break;

    default:
        break;
    }
}

QList<EmailData> parseMBOX(QString fileName)
{
    // parse mbox and create EmailData objects
    QList<EmailData> emails;

    return emails;
}
