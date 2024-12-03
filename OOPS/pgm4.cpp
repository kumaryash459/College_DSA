//  program for bank employee to print name of the employee,account_no, and balance and print invalid balace of less than 500.
#include <iostream>
using namespace std;
class BankEmployee
{
    public:
    string name;
    int account_no;
    float balance;

    void Display()
    {  
        cout<<"Name: "<<name<<endl;
        cout<<"Account No: "<<account_no<<endl;
        if(balance<500)
        cout<<"Invalid balance";
        else
        cout<<"Balance: "<<balance;
    }

    void withdrawl(float amount)
    {
        if(balance - amount <500)
        cout<<"Withdrawl failed because balance cannot go less that 500"<<endl;
        else
        balance = balance - amount;
        cout<<"amount withdrawl: "<<amount<<endl;
        cout<<"balace : "<<balance<<endl;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout<<"amount deposit: "<<amount<<endl;
    }
};

int main()
{
    BankEmployee emp;
    cout<<"Enter employee name: "<<endl;
    cin>>emp.name;
    cout<<"Enter account no: "<<endl;
    cin>>emp.account_no;
    cout<<"Enter initial balance: "<<endl;
    cin>>emp.balance;
    emp.Display();
    double deposit_amount, withdrw_amount;
    cout<<"\nEnter amount to deposit: "<<endl;
    cin>>deposit_amount;
    emp.deposit(deposit_amount);
    cout<<"Enter the amount to withdraw: "<<endl;
    cin>>withdrw_amount;
    emp.withdrawl(withdrw_amount);
}