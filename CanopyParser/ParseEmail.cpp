#include "ParseEmail.h"

#include <QDebug>
#include <QFile>
#include <QStringRef>
#include <QString>
#include <QTime>
#include <QMap>

#define 	LINE_LENGTH		100

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

    QTextStream can(&canFile);
    QTextStream ins(&insFile);
    QTextStream txt(&txtFile);

    QString line = in.readLine();
    int fileLoc = 0;
    qDebug() << "Opening file";
    while (!line.isNull())
    {
//        qDebug() << line;

        // parse content to can file
        parseMIMEHeader(&in, &can, &line, &fileLoc, dataFilePath);
        parseMIMEContent(&in, &can, &ins, &txt,
                         &line, &fileLoc);

        line = in.readLine();
        fileLoc++;
    }
}

void parseFoldersEML(QString dataPath, QString sessionPath)
{
    qDebug() << "Parsing EML folders from " << dataPath <<
                " into " << sessionPath;
}


/*****************************
 * Helper functions
*****************************/

void parseMIMEHeader(QTextStream *dataFile, QTextStream *canFile,
                     QString *line, int *fileLoc, QString fileName)
{
    int startLoc = *fileLoc;

    bool from = false;
    bool to = false;

    QString sender;
    QString receiver;
    QString subject;
    QString date;
    while (!line->isNull() && line->left(12) != QString("Content-Type"))
    {
        if (line->left(5) == "From:")
        {
            from = true;
            parseEmailString(*line, &sender);
        }
        else if (line->left(3) == "To:")
        {
            to = true;
            parseEmailString(*line, &receiver);
        }
        else if (line->left(8) == "Subject:")
        {
            subject = line->mid(9, line->length() - 8);
        }
        else if (line->left(5) == "Date:")
        {
            date = line->mid(6, line->length() - 5);
            date = date.left(date.length() - 6);

//            email->dateTime = parseMIMEDateString(date);
        }

        *line = dataFile->readLine();
        *fileLoc = *fileLoc + 1;
    }

    qDebug() << "sender: " << sender;
    qDebug() << "receiver: " << receiver;
    qDebug() << "subject: " << subject;
    qDebug() << "date: " << date;

    // write to can file
    QString data = "email,";
    data += fileName + ",";
    data += QString::number(startLoc) + ",";
    // send
    data += sender + ",";
    // receive
    data += receiver + ",";
    // date
    data += date + ",";
    // subject
    data += subject;

    int numLines = data.length() / LINE_LENGTH;
    data = QString::number(numLines) + "," + data;

    qDebug() << data;

    // split data
    for (int i = 0; i < numLines; i++)
    {
        // write LINE_LENGTH chunks
        *canFile << data.mid(i*LINE_LENGTH, LINE_LENGTH) << endl;
    }

    *canFile << data.mid(numLines * LINE_LENGTH, data.length() - (numLines*LINE_LENGTH));
    for (int i = data.length() - numLines * LINE_LENGTH; i < LINE_LENGTH; i++)
        *canFile << 0x00;
    *canFile << endl;

    // split data if over
    /*if (data.length() < LINE_LENGTH)
    {
        // pad with zeros
        // write data to file
        *canFile << data;
        for (int i = data.length(); i < LINE_LENGTH; i++)
            *canFile << 0x00;
        *canFile << endl;
    }
    else
    {
        // split data
        for (int i = 0; i < data.length() - LINE_LENGTH; i += LINE_LENGTH)
        {

        }
        // pad last one with zeros
    }
    */
}

void parseMIMEContent(QTextStream *dataFile, QTextStream *canFile, QTextStream *insFile, QTextStream *txtFile,
                      QString *line, int *fileLoc)
{
    QString previousLocation = QString("");

    while (!line->isNull() && line->left(10) != QString("X-GM-THRID"))
    {


        *line = dataFile->readLine();
        *fileLoc++;
    }
}

void parseEmailString(QString line, QString* address)
{
    bool found = false;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '<')
        {
            found = true;
            // find '>', if not end get next email
            int start = i + 1;
            while (line.at(i) != '>' && i < line.length() - 1)
                i++;

            *address = *address + line.mid(start, i - start);
            if (i != line.length() - 1)
                *address += ", ";
        }
        else if (line.at(i) == '[')
        {
            //qDebug() << line;
            // UPDATE: This shouldn't happen if parsing is done right
        }
    }

    if (!found)
    {
        // email not in address book, follows different format
        *address = line.right(line.length() - 4);
    }
}

QDateTime parseMIMEDateString(QString dateString)
{
    QDateTime date;
    int d, m, y;

    int i = 0;

    // get date
    if (dateString.at(i).isLetter())
        i += 5;

    int start = i;
    while (dateString.at(i) != ' ')
        i++;

    d = dateString.mid(start, i - start).toInt();

    // get month
    i+=1; // move past empty space
    start = i;
    while (dateString.at(i) != ' ')
        i++;

    m = getMonthIndex(dateString.mid(start, i - start));

    // get year
    i+=1; // move past empty space
    start = i;
    while (dateString.at(i) != ' ')
        i++;

    y = dateString.mid(start, i - start).toInt(); // get only last 2 digits

    // get time
    i+=1; // move past empty space
    int h = dateString.mid(i, 2).toInt();
    i+=3;
    int min = dateString.mid(i, 2).toInt();
    i+=3;
    int s = dateString.mid(i, 2).toInt();

    date.setDate(QDate(y, m, d));
    date.setTime(QTime(h, min, s));

    return date;
}

int getMonthIndex(QString month)
{
    QMap<QString,int> months;

    months.insert("Jan", 1);
    months.insert("Feb", 2);
    months.insert("Mar", 3);
    months.insert("Apr", 4);
    months.insert("May", 5);
    months.insert("Jun", 6);
    months.insert("Jul", 7);
    months.insert("Aug", 8);
    months.insert("Sep", 9);
    months.insert("Oct", 10);
    months.insert("Nov", 11);
    months.insert("Dec", 12);

    return months.value(month);
}



