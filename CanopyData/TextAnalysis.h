#include <QMap>
#include <QString>
#include "../CanopyParser/EmailData.h"

QMap<QString, int> getWordCount(QString content);

void getWordFreq(QString line, QList<WordFreq>* wordCounts, QList<QString>* words, EmailData* email, QString userEmail);
