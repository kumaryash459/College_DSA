/*program using constructor in deriver classes to initialise alpha, beta,gamma and display corresponding values*/

#include <iostream>
#include <conio.h>
using namespace std;
class Alpha
{
    protected:
        int alpha;
    public:
        Alpha(int a):alpha(a){}

};
class Beta : public Alpha
{
    protected: int beta;
    public: Beta(int a, int b):Alpha(a),beta(b){}
};
class Gamma : public Beta
{
    private: int gamma;
    public: Gamma(int a, int b, int c):Beta(a,b),gamma(c){}
    void displayValues()
    {
        cout<<"Alpha: "<<alpha<<endl;
        cout<<"Beta: "<<beta<<endl;
        cout<<"Gamma: "<<gamma<<endl;
    }
};

int main()
{
    Gamma g(10,20,30);
    g.displayValues();
    return 0;
}