#ifndef EMAILPARSER_H
#define EMAILPARSER_H

#include <QString>
#include <QList>
#include "../CanopyData/TextAnalysis.h"
#include <QTextStream>

enum EmailFileType
{
    MBOX,
    EML,
    NONE
};

QList<LocalEmailData> parseEmailWarrant(QString fileName);

// specific file parsers
QList<LocalEmailData> parseMBOX(QString fileName);

void parseEmailString(QString line, QString* address);

void parseMIMEHeader(LocalEmailData* email, QTextStream* in, QString* line, int* fileLoc);

void parseMIMEContent(LocalEmailData* email, QTextStream* in, QString* line, int* fileLoc);

QDateTime parseMIMEDateString(QString dateString);
int getMonthIndex(QString month);

#endif // EMAILPARSER_H
