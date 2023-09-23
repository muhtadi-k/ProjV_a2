#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string FName;
    string LName;
};

int main()
{
    //variable declaration
    string line;
    ifstream file;
    STUDENT_DATA test;
    vector<STUDENT_DATA> v;

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
       
        cout << test.LName << test.FName << endl;
    }
    

    file.close();
    return 1;
}
