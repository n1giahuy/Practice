#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    char ob;
    double a;
    double b;
    double c;

    cout<<"*******CALCULATOR*******" << '\n';
    cout<<"Enter either(+,-,*,/): ";
    cin >>ob;

    //Add variables
    cout<<'\n';
    cout<<"Please give a number 'a': ";
    cin>>a;
    cout<<"Please give a number 'b': ";
    cin>>b;

    //Choose four basic operations
    switch (ob)
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
    case '*':
        c=a*b;
        break;
    case '/':
        c=a/b;
        break;
    default:
        cout<<"Invalid math!";
        break;
    }
    
    cout<<'\n';
    cout<<"Your result: "<< c <<'\n';
    cout<<"************************";
    return 0;
}
