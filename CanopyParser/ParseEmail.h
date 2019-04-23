#ifndef PARSEEMAIL_H
#define PARSEEMAIL_H

#include <QString>
#include <QDir>

void parseMBOX(QString dataPath, QString sessionPath, QString contentName);

void parseFoldersEML(QString dataPath, QString sessionPath);

#endif // PARSEEMAIL_H
