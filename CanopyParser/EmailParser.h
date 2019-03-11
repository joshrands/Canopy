#ifndef EMAILPARSER_H
#define EMAILPARSER_H

#include <QString>
#include <QList>
#include "EmailData.h"
#include <QTextStream>

enum EmailFileType
{
    MBOX,
    EML,
    NONE
};

QList<EmailData> parseEmailWarrant(QString fileName);

// specific file parsers
QList<EmailData> parseMBOX(QString fileName);

void parseEmailString(QString line, QString* address);

void parseMIMEHeader(EmailData* email, QTextStream* in, QString* line, int* fileLoc);

void parseMIMEContent(EmailData* email, QTextStream* in, QString* line, int* fileLoc);




#endif // EMAILPARSER_H
