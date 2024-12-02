//Develop a c++ program to write and read time in form binary file using fsream
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define FILE_NAME "time.dat"
void writeTime(int h, int m, int s)
{
    char str[10];
    fstream file;
    file.open(FILE_NAME,ios::out|ios::binary);
    if(!file)
    {
        cout<<"Error in creating file!!!"<<endl;
        return;
    }
    sprintf(str,"%02d:%02d:%02d",h,m,s);
    file.write(str,sizeof(str));
    cout<<"Time "<<"has been written into file"<<endl;
    file.close();
}
void readTime(int *h, int *m, int *s)
{
    char str[10];
    int inH,inM,inS;
    fstream finC;
    finC.open(FILE_NAME,ios::in|ios::binary);
    if(!finC)
    {
        cout<<"Error in opening file!!!"<<endl;
        return;
    }
    if(finC.read((char*)str,sizeof(str)))
    {
        scanf(str,"%02d:%02d:%02d",&inH,&inM,&inS);
        *h=inH;
        *m=inM;
        *s=inS;
    }
    finC.close();
}
int main()
{
    int h,m,s;
    cout<<"Enter Time:\n";
    cout<<"Enter hour:";
    cin>>h;
    cout<<"Enter minute: ";
    cin>>m;
    cout<<"Enter second: ";
    cin>>s;
    writeTime(h,m,s);
    h=m=s=0;
    readTime(&h,&m,&s);
    cout<<"The time is "<<setw(2)<<setfill('0')<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s<<endl;
}
