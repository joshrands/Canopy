#ifndef EMAILPARSER_H
#define EMAILPARSER_H

#include <QString>
#include <QList>
#include "EmailData.h"

enum EmailFileType
{
    MBOX,
    EML
};

QList<EmailData> parseEmailWarrant(QString fileName);

// specific file parsers
QList<EmailData> parseMBOX(QString fileName);

#endif // EMAILPARSER_H
