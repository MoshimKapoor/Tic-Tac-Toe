#include<iostream>
#include<vector>
#include <string>
using namespace std;


void displayBoard( const char board[3][3]){
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
     cout<<"   |   |   "<<endl;

}
int main() {
    char board[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    displayBoard(board);

    const char playerX='X';
    const char playerO='O';

    char currentplayer=playerX;
    char winner=' ';
    int r=-1;
    int c=-1;
    for(int i=0;i<9;i++)
    {
        displayBoard(board);
        cout<<"Current Player is "<<currentplayer<<endl;
        while(true){
            cout<<"Enter r c from 1-3 for row and column ";
            cin>>r >> c;
            if(c<1 || c>3|| r<1 ||r>3){
                cout<<"Invalid input, Try again."<<endl;
            }
            else if(board[r-1][c-1]!=' ') {
                cout<<"Tile is full, Try again."<<endl;
            }
            else break;
            r=-1;
            c=-1;
            cin.clear();
            cin.ignore(10000,'\n');
        }

        board[r-1][c-1]=currentplayer;
        currentplayer=(currentplayer==playerX) ? playerO : playerX;

        //check winner

        //row winning condition
        for(int r=0;r<3;r++){
            if(board[r][0]!=' ' && board[r][0]==board[r][1] && board[r][1]==board[r][2]){
                winner=board[r][0];
                break;
            }
        }

        //column winning condition
        for(int c=0;c<3;c++){
            if(board[0][c]!=' ' && board[0][c]==board[1][c] && board[1][c]==board[2][c]){
                winner=board[0][c];
                break;
            }
        }

        //diagonal winning condition
        if(board[0][0]!=' ' && board[1][1]==board[2][2] && board[0][0]==board[1][1]){
            winner=board[0][0];
        }

        if(board[0][2]!=' ' && board[1][1]==board[2][0] && board[0][2]==board[1][1]){
            winner=board[0][2];
        }
        if(winner!=' ') break;
    }
    if(winner!=' '){
        cout<<"Player "<<winner<<" is the winner!"<<endl;
    }
    else{
        cout<<"Tie!"<<endl;
    }

    return 0;
}