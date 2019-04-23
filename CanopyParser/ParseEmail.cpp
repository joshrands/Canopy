#include "ParseEmail.h"

#include <QDebug>
#include <QFile>
#include <QStringRef>
#include <QString>
#include <QTime>
#include <QMap>

void parseMBOX(QString dataPath, QString sessionPath, QString contentName)
{
    qDebug() << "Parsing " << contentName << " from " << dataPath
             << " and storing in " << sessionPath;

    // make folder for can data
    QString dir = QString(sessionPath + "/session/" + contentName);
    QDir().mkdir(dir);
    // make .can and .ins files
    QFile canFile(dir + "/" + contentName + ".can");
    QFile insFile(dir + "/" + contentName + ".ins");
    QFile txtFile(sessionPath + "/session/working/" + contentName + ".txt");

    if (!canFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .can file.";
    }
    if (!insFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .ins file.";
    }
    if (!txtFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error creating .txt file.";
    }

    // open data file
    QFile dataFile(dataPath);

    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file: " << dataPath;
        return;
    }

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
