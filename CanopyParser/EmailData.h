
/*
EmailData class
Stores important identifier information for email and pointers to where data is in parent file
*/

#include <QDateTime>

using namespace std;

class EmailData
{
public:
    EmailData(); // default constructor

    QString senderAddress;
    QString receiverAddress;
    QString subjectLine;
    QDateTime dateTime;

    QString parentFileName;

    int rawDataLocation; // byte location of raw data in parent file
    int rawDataLength; // byte length of raw data in parent file

    int htmlLocation; // byte location of html in parent file
    int htmlLength; // byte length of html in parent file

private:

};
