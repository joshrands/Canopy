#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <fstream>

using namespace std;



//email class which should have everything we want, whereinMBOX needs work
class Email {

   public:
    Email(string d, string s, string f, string t, vector<string> b){
        date=d;
        subject=s;
        from=f;
        to=t;
        body=b;
    }
      string date;
      string subject;
      vector<string> body;
      string from;
      string to;
      int whereInMBOX;



};



//function to get email data from filename
Email getMyEmail(string filename){
    //things to store stuff in!
    string date;
    string subject;
    vector<string> body;
    string from;
    string to;
    int startbody;
    int endbody;

    vector <string> data;

    string line;


    //the email to read from
    ifstream inFile(filename);

    if (inFile.is_open())

    {

        while(getline(inFile, line))

        {

            data.push_back(line);

            //cout << data << endl;

        }

    }
    else{
        cout<< "Didn't work"<<endl;
    }
    //TODO do this for multiple file formats
    for (int i =0; i<data.size(); ++i){

        if (data.at(i).substr(0,5)=="From:"){
            from=data.at(i);
        }
        else if (data.at(i).substr(0,3)=="To:"){
            to=data.at(i);
        }
        else if (data.at(i).substr(0,8)=="Subject:"){
            subject=data.at(i);
        }
        else if (data.at(i).substr(0,5)=="Date:"){
            date=data.at(i);
        }
        else if (data.at(i).substr(0,23)=="Content-Type: text/html"){
            startbody=i;
        }
        else if (data.at(i).substr(0,13)=="Content-Type:"){
            endbody=i;
        }



    }

    //cout<<from<<endl<<to<<endl<<subject<<endl<<date<<endl;
    //makes the body
    for (int j=startbody; j<endbody-1 ; ++j){
        body.push_back(data.at(j));
    }


//    for (int jj=0; jj<body.size() ; ++jj){
//        cout<<body.at(jj)<<endl;
//    }

Email mymail(date,subject,from,to,body);


    return mymail;







}




int main() {


    Email please= getMyEmail("Hehe.eml");

    //cout<<please.subject;

    return 0;
}