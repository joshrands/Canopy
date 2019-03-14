
#include "../CanopyData/TextAnalysis.h"
#include <QDebug>
#include <QStringList>

QMap<QString, int> getWordCount(QString content)
{
   QMap<QString, int> wordCounts;

   return wordCounts;
}

void getWordFreq(QString line, QList<WordFreq>* wordCounts, QList<QString>* words)
{
    QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
//    QStringList badWords;
//    badWords << "a" << "to" << "you";

    for (int i = 0; i < list.length(); i++)
    {
        if (list.at(i).length() > 1)
        {
            if (words->contains(list.at(i)))
            {
                // increment existing
                int index = words->indexOf(list.at(i));
                (*wordCounts)[index].count = wordCounts->at(index).count + 1;
            }
            else
            {
                WordFreq word;
                word.count = 1;
                word.word = list.at(i);

                wordCounts->append(word);
                words->append(list.at(i));
            }
        }
    }
}


