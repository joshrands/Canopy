#include "ParseEmail.h"

#include <QDebug>
#include <QFile>
#include <QStringRef>
#include <QString>
#include <QTime>
#include <QMap>

/*
void parseMBOX(QFile* dataFile, QFile* canFile, QFile* insFile, QFile* txtFile)
{
    QTextStream in(dataFile);

    qDebug() << "Reading line by line";

    QString line = in.readLine();
    int fileLoc = 0;

    while (!line.isNull())
    {
        qDebug() << line;
        line = in.readLine();
        fileLoc++;
    }
}
*/

void parseMBOX(QString dataFilePath, QString sessionFilePath, QString contentName)
{
    qDebug() << "Parsing " << contentName << " from " << dataFilePath
             << " and storing in " << sessionFilePath;

    // open data file
    QFile dataFile(dataFilePath);

    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file: " << dataFilePath;
        return;
    }

    // open can, ins, and txt files
    QString dir = sessionFilePath + "/session/" + contentName + "/";

    QFile canFile(dir + contentName + ".can");
    if (!canFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error opening can file";
    }
    QFile insFile(dir + contentName + ".ins");
    if (!insFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error opening ins file";
    }
    QFile txtFile(sessionFilePath + "/session/working/" + contentName + ".txt");
    if (!txtFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error opening txt file";
    }

    qDebug() << "Files created. Parsing...";

    QTextStream in(&dataFile);

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
