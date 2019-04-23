#ifndef PARSEEMAIL_H
#define PARSEEMAIL_H

#include <QString>
#include <QDir>

//void parseMBOX(QFile* dataFile, QFile* canFile, QFile* insFile, QFile* txtFile);

void parseMBOX(QString dataFilePath, QString sessionFilePath, QString contentName);

void parseFoldersEML(QString dataPath, QString sessionPath);

#endif // PARSEEMAIL_H
