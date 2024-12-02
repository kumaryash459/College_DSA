#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int main()
{
    ofstream outFile("sample.txt");
    if(!outFile)
    {
        cout<<"Error creating the file"<<endl;
        return 1;
    }
    outFile<<"Hello is some text written to the files.\n";
    outFile<<"This is another line in the file";
    outFile.close();
    ifstream inFile("sample.txt");
    if(!inFile){
        cout<<"Error opening the file"<<endl;
        return 1;
    }
    cout<<"contents if the file:"<<endl;
    char ch;
    inFile.close();
    return 0;
}