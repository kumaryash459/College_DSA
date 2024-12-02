// program using classes display student name, roll number, marks obtained in two subjects and total score of student
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
class student
{
    private:
    char name[10];
    int roll;
    int marks1,marks2;

    public :
    void setDetails()
    {
        cout<<"Enter name of student : ";
        // getline(cin,name);
        gets(name);
        cout<<"Enter roll number of student : ";
        cin>>roll;
        cout<<"Enter marks obtained in subject 1 : ";
        cin>>marks1;
        cout<<"Enter marks obtained in subject 2 : ";
        cin>>marks2;
    }
    float calculatemarks()
    {
        return marks1 + marks2;
    };

    void diaplay()
    {
        cout<<"Name of student : "<<name<<endl;
        cout<<"Roll number of student : "<<roll<<endl;
        cout<<"Marks obtained in subject 1 : "<<marks1<<endl;
        cout<<"Marks obtained in subject 2 : "<<marks2<<endl;
        cout<<"Total marks: "<<calculatemarks();     
    }
};

int main()
{
    student s1;
    s1.setDetails();
    s1.diaplay();
    return 0;
}