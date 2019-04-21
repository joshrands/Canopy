#include <QMap>
#include <QString>
#include "../CanopyParser/LocalEmailData.h"

QMap<QString, int> getWordCount(QString content);

void getWordFreq(QString line, QList<WordFreq>* wordCounts, QList<QString>* words, LocalEmailData* email, QString userEmail);
