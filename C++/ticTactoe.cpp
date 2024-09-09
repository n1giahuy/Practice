#include<iostream>
#include<ctime>

using namespace std;
    
//Global variables  
char board[3][3]={
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
char player='X';
char computer='O';
char winner=' ';
char response=' ';

//Add functions
void drawBoard();
void playerMove();
void computerMove();
int checkFreespace();
char checkWinner();
void printWinner(char winner);
void resetBoard();


int main()
{   
   do{

    resetBoard();

    while(true){
        drawBoard();
        playerMove(); 

        computerMove();

       

        if (checkWinner()!=' ' || checkFreespace()==0)
        {
            drawBoard();
            winner=checkWinner();
            printWinner(winner);
            cout<<"Play again: (Y/N)\n" ;
            cin>>response;
            response=toupper(response);
            if (response=='Y')
            {
                resetBoard();
            }
            else if(response=='N')
                break;
        }      

        

    }} while(response=='Y' ) ;
        

    cout<<"Thank you for playing!";
    return 0;
}

void drawBoard(){

    //Draw board

    cout<<"  "<<board[0][0]<<" | "<<board[0][1]<<" "<<"| "<<board[0][2]<<"\n";
    cout<<"-------------\n";
    cout<<"  "<<board[1][0]<<" | "<<board[1][1]<<" "<<"| "<<board[1][2]<<"\n";
    cout<<"-------------\n";
    cout<<"  "<<board[2][0]<<" | "<<board[2][1]<<" "<<"| "<<board[2][2]<<"\n";
    
}

void resetBoard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=' ';
        }
        
    }
    
}
void playerMove(){

    int rows=0;
    int columns=0;


    
    do
    {
        cout<<"Enter rows(1-3): ";
        cin>>rows;
        cout<<"Your columns(1-3): ";
        cin>>columns;
        
        rows--;
        columns--;

        if (board[rows][columns]==' ' )
        { 
            
            board[rows][columns]=player;
            break;
        }
        
        else
        {
            cout<<"Invalid move!\n";
            cin.clear();
            fflush(stdin);
        }
    } while (true); 
    

}
void computerMove(){

    int rows=0;
    int columns=0;
    srand(time(0));
    
    if (checkFreespace()>0)
    {
        do{
            rows=rand()%3;
            columns=rand()%3;
        }while(board[rows][columns]!=' ');
    }
    

    board[rows][columns]=computer;
    
    
}

int checkFreespace(){

    int spaces=9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                spaces--;
            }
            
        }
        
    }
    
    return spaces;
}

char checkWinner(){

    //Check columns
    for (int i = 0; i < 3; i++)
    {
        if ( board[0][i]==board[1][i] && board[1][i] ==board[2][i])
        {
            return board[0][i];   
        }
    }

    //Check rows
    for (int i = 0; i < 3; i++)
    {
        if ( board[i][0]==board[i][1] && board[i][0] ==board[i][2])
        {
            return board[i][0];   
        }
    }

    //Check diagonals
    if ((board[0][0]==board[1][1]&& board[1][1]==board[2][2]) 
        || (board[0][2]==board[1][1]&& board [1][1] ==board[2][0]))
    {
        return board[1][1];
    }
    
    else
        return ' ';
      
}

void printWinner(char winner){
    if (winner==player)
    {
        cout<<"YOU WIN! CONGRATULATION.";
    }
    else if(winner==computer)
    {
        cout<<"YOU LOSE!";
    }
    
    else
        cout<<"IT'S TIE!";
    
}