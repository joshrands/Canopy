
/*
EmailData class
Stores important identifier information for email and pointers to where data is in parent file
*/

#include <QDateTime>

using namespace std;

class LocalEmailData
{
public:
    LocalEmailData(); // default constructor

    bool operator<(const LocalEmailData& other) const {
        return dateTime > other.dateTime; // sort by namefile
    }

    QString senderAddress;
    QString receiverAddress;
    QString subjectLine;
    QDateTime dateTime;
    QString dateString;

    QString parentFileName;

    int rawDataLocation; // byte location of raw data in parent file
    int rawDataLength; // byte length of raw data in parent file

    int htmlLocation; // byte location of html in parent file
    int htmlLength; // byte length of html in parent file

    int textLocation;
    int textLength;

    QList<QString> keywords;

private:

};

class WordFreq
{
public:
    WordFreq(); // default constructor
    WordFreq(int rank, QString word, int count)
    {
        this->rank = rank;
        this->word = word;
        this->count = count;
    }

    bool operator<(const WordFreq& other) const {
        return count > other.count; // sort by namefile
    }

    void setCount(int count) { this->count = count; }

    int rank;
    QString word;
    int count;
};
