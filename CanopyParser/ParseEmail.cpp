#include "ParseEmail.h"

#include <QDebug>
#include <QFile>
#include <QStringRef>
#include <QString>
#include <QTime>
#include <QMap>

void parseMBOX(QString dataPath, QString sessionPath)
{
    qDebug() << "Parsing " << dataPath << " and storing in " << sessionPath;

    // open data file
    QFile file(dataPath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file: " << dataPath;
        return;
    }

    QTextStream in(&file);

    QString line = in.readLine();
    int fileLoc = 0;
    qDebug() << "Opening file";
    while (!line.isNull())
    {
        qDebug() << line;
        line = in.readLine();
        fileLoc++;
    }
}

void parseFoldersEML(QString dataPath, QString sessionPath)
{
    //

}
