#include<iostream>

using namespace std;

int getDigit(const int number);
int getevenNum(const string CreNums);
int getoddNum(const string CreNums);

int main()
{
    int result=0;
    string CreNums;
    cout<<"Enter your credit card number: ";
    cin>>CreNums;

    
    result=getevenNum(CreNums)+getoddNum(CreNums);
    cout<<result<<"\n";
    if (result%10==0)
    {
        cout<<"Valid! \n";
    }
    else
        cout<<"Invalid! \n";
    
    return 0;
}

int getDigit(const int number){
    return number%10+ (number/10);
}

int getevenNum(const string CreNums){

    int sum=0;

    for (int i= CreNums.size()-2 ;i>=0 ; i-=2)
    {
        sum+= getDigit((CreNums[i]-'0')*2);
    }

    return sum;   
}

int getoddNum(const string CreNums){
    int sum=0;
    for (int i= CreNums.size()-1 ;i>=0 ; i-=2)
    {
        sum+= CreNums[i]-'0';
    }   

    return sum;
}