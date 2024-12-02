/*program to implement multiple inheritance for performing arithmatic operation of two number*/
#include <iostream>
#include <conio.h>
using namespace std;
class Addition
{
    public:
        int add(int a, int b)
        {
            return a + b;
        }
};
class Subtraction
{
    public:
        int sub(int a, int b)
    {
        return a - b;
    }
};
class arithmatic: public Addition, public Subtraction
{
    public: 
        void display(int a , int b)
        {
            cout<<"sum: "<< add(a,b);
            cout<<"Difference: "<< sub( a,b);
        }
};

int main()
{
    arithmatic obj;
    int num1, num2;
    cout<<"Enter two number: ";
    cin>>num1>>num2;
    obj.display(num1, num2);
    return 0;
}