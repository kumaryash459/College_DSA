//operator overloading

#include <iostream>
#include <conio.h>
using namespace std;
class Number
{
    private:
        int value;
    public:
        Number():value(0){}
        Number(int val): value(val){}
        Number operator -() const
        {
            Number result(-value);
            return result;
        }
    void display() const
    {
        cout<<"Value "<<value<<endl;
    }
};

int main()
{
    Number num1(10);
    Number num2= -num1;
    cout<<"Original Number: ";
    num1.display();
    cout<<"After unary minus: ";
    num2.display();
}