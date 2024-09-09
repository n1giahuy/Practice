#include<iostream>
#include<iomanip>



using namespace std;

void showBalance(double balance);
double deposit();
double withdraw();

double money;

double amount;

int main() 
{
    int option;

        do{   
        
        cin.clear();
        fflush(stdin);


        cout<<"**********************\n";
        cout<<"Enter your choice \n";
        cout<<"**********************\n";
        cout<<"1. Show Balance\n";
        cout<<"2. Deposit Money\n";
        cout<<"3. Withdraw Money\n";
        cout<<"4. Exit\n";    
        cin>>option;

        switch (option)
        {
        case 1:
            showBalance(money);
            break;
        case 2:
            money+=deposit();
            showBalance(money);
            break;
        case 3:
            money-=withdraw();
            showBalance(money);
            break;    
        case 4:
            cout<<"Thank you!";
            break;
        
        default:
            cout<<"Invalid syntax!\n";
            break;
        }
        }while(option !=4 );


    return 0;
}

void showBalance(double balance)
{
    cout<<"Your balance is: $"<<setprecision(2)<<fixed<<balance<<'\n';
}

double deposit()
{
    cout<<"Add the deposit money: ";

    do
    {
        cin>>amount;
        
        if(amount<0)
        {
        cout<<"Invalid! Please try again: ";
        }

    } while (amount<0 );
    
    

    return amount;
    
}

double withdraw()
{
    cout<<"Add the withdraw money: ";

    do
    {
        cin>>amount;
        
        if(amount<0|| amount>money)
        {
        cout<<"Invalid! Please try again: \n";
        }

    } while (amount<0 || amount>money);

    return amount;
}

