#include<bits/stdc++.h>
#include<ncurses.h>
using namespace std;
#define n 8

void printBoard(int board[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}

bool valid(int sx, int sy, int board[n][n]){
    if(sx<n && sy<n && sx>=0 && sy>=0 && board[sx][sy] == -1)
        return true;
    return false;
}

bool solve(int board[n][n], int sx, int sy, int mv, int dx[n], int dy[n]){
    if(mv == n*n)return true;

    
    for(int i=0; i<8; i++){
        int x = sx + dx[i], y = sy + dy[i];
        // clrscr();
        // printBoard(board);
        // system("clear");
        if(valid(x,y, board) && board[x][y] == -1){
            board[x][y] = mv;
            if(solve(board, x, y, mv+1, dx, dy)){
                return true;
            }
            else
                board[x][y] = -1;
        }
    }
   
    return false;
}

int main(){
    int board[n][n];
    memset(board, -1, sizeof(board));
    board[0][0] = 0;
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    if(solve(board, 0, 0, 1, dx, dy)){
        printBoard(board);
    }
    return 0;
}


