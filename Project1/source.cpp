#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
//#define PRE_RELEASE

struct STUDENT_DATA
{
    string FName;
    string LName;
    string Email;
};

int main()
{
    #ifdef _DEBUG
        cout << "debug build\n";
    #else
        cout << "release build\n";
    #endif
      
    #ifdef PRE_RELEASE
            cout << "pre-release build\n";
    #else
            cout << "standard build\n";
    #endif


    //variable declaration
    string line;
    ifstream file;
    STUDENT_DATA test;
    vector<STUDENT_DATA> v;

        #ifdef PRE_RELEASE
        //open data
        file.open("StudentData_Emails1.txt");

        //check if file opened
        if (!file.is_open()) {
            cerr << "File can't be opened! " << endl;
            system("PAUSE");
            exit(1);
        }

        //read file by line
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, test.LName, ','); //seperate lines into last and first name using comma
            getline(ss, test.FName, ',');   // and store into 'test' object
            getline(ss, test.Email, ',');   // and store into 'test' object
            v.push_back(test); //push object into vector  
            cout << test.LName << test.FName << " " + test.Email << endl;
            }

    #else

        //open data
        file.open("StudentData.txt");

        //check if file opened
        if (!file.is_open()) {
            cerr << "File can't be opened! " << endl;
            system("PAUSE");
            exit(1);
        }

        //read file by line
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, test.LName, ','); //seperate lines into last and first name using comma
            getline(ss, test.FName, ',');   // and store into 'test' object
            v.push_back(test); //push object into vector  

            #ifdef _DEBUG
            cout << test.LName << test.FName << endl;
            #endif

        }

        #endif

    file.close();
    return 1;
}
