
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

private:
    QString senderAddress;
    QString receiverAddress;
    QString subjectLine;
    QDateTime dateTime;

    QString parentFileName;

    int rawDataLocation;
    int htmlLocation;
};
