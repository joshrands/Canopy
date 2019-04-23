#ifndef PARSEEMAIL_H
#define PARSEEMAIL_H

#include <QString>
#include <QDir>
#include <QList>
#include "../CanopyData/TextAnalysis.h"
#include <QTextStream>
#include <QFile>

//void parseMBOX(QFile* dataFile, QFile* canFile, QFile* insFile, QFile* txtFile);

void parseMBOX(QString dataFilePath, QString sessionFilePath, QString contentName);

void parseFoldersEML(QString dataPath, QString sessionPath);

void parseMIMEHeader(QTextStream *dataFile, QTextStream *canFile,
                     QString *line, int *fileLoc, QString fileName);

void parseMIMEContent(QTextStream *dataFile, QTextStream *canFile, QTextStream *insFile, QTextStream *txtFile,
                      QString *line, int *fileLoc);

void parseEmailString(QString line, QString* address);
QDateTime parseMIMEDateString(QString dateString);
int getMonthIndex(QString month);


#endif // PARSEEMAIL_H
