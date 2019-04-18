
#include "../CanopyData/TextAnalysis.h"
#include <QDebug>
#include <QStringList>

QMap<QString, int> getWordCount(QString content)
{
   QMap<QString, int> wordCounts;

   return wordCounts;
}

void getWordFreq(QString line, QList<WordFreq>* wordCounts, QList<QString>* words, EmailData* email, QString userEmail)
{
    QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    string array[] = { "the","of","and","to","a","in","for","is","on","that","by","this","with","i","you","it","not","or",
                       "be","are","from","at","as","your","all","have","new","more","an","was","we","will","home","can",
                       "us","about","if","page","my","has","search","free","but","our","one","other","do","no","information",
                       "time","they","site","he","up","may","what","which","their","news","out","use","any","there","see",
                       "only","so","his","when","contact","here","business","who","web","also","now","help","get","pm","view",
                       "online","c","e","first","am","been","would","how","were","me","s","services","some","these","click",
                       "its","like","service","x","than","find"
                       "content-transfer-encoding:", "!important;", "quoted-printable","7bit","content-type:","text/html;","width:","0px;",
                        "font-size:","charset=iso-8859-1","float:","margin-bottom:","100%"};

    QList<QString> badWords;

    for (int i = 0; i < 112; i++)
    {
        badWords.append(QString::fromStdString(array[i]));
    }

    for (int i = 0; i < list.length(); i++)
    {
        QString word = list.at(i).toLower();
//        qDebug() << "|" << word << "|";
        if (list.at(i).length() > 1 && !badWords.contains(word))
        {
            if (!email->keywords.contains(word))
                email->keywords.append(word);

            if (words->contains(word))
            {
                // increment existing
                int index = words->indexOf(word);
                (*wordCounts)[index].count = wordCounts->at(index).count + 1;
            }
            else
            {
                WordFreq wordFreq;
                wordFreq.count = 1;
                wordFreq.word = word;

                wordCounts->append(wordFreq);
                words->append(word);
            }
        }
    }

    // add email addresses to word count
/*    if (email->senderAddress != userEmail)
    {
        if (words->contains(email->senderAddress))
        {
            // increment existing
            int index = words->indexOf(email->senderAddress);
            (*wordCounts)[index].count = wordCounts->at(index).count + 1;
        }
        else
        {
            WordFreq word;
            word.count = 1;
            word.word = email->senderAddress;

            wordCounts->append(word);
            words->append(email->senderAddress);
        }
    }

    if (email->receiverAddress != userEmail)
    {
        if (words->contains(email->receiverAddress))
        {
            // increment existing
            int index = words->indexOf(email->receiverAddress);
            (*wordCounts)[index].count = wordCounts->at(index).count + 1;
        }
        else
        {
            WordFreq word;
            word.count = 1;
            word.word = email->receiverAddress;

            wordCounts->append(word);
            words->append(email->receiverAddress);
        }
    }
    */
}


