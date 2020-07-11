/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSafeMove(vector<vector<char>>& board,int& row, int& col,int& n){
    for(int i=0;i<n;i++){
        if(board[i][col] == 'Q')
            return false;
    }

    int r = row + 1;
    int c = col + 1;
    while( r<n && c<n){
        if(board[r][c] == 'Q')
            return false;
        r++;
        c++;
    }

    r = row - 1;
    c = col - 1;
    while( r>=0 && c>=0){
        if(board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row - 1;
    c = col + 1;
    while( r>=0 && c<n){
        if(board[r][c] == 'Q')
            return false;
        r--;
        c++;
    }

    r = row + 1;
    c = col - 1;
    while( r<n && c>=0){
        if(board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }
    return true;
}

void number_of_ways(vector<vector<char>>& board,int& size,int row_number,int& count){
    if(row_number == size){
        count++;
        return;
    }
    else{
        for(int i=0;i<size;i++){
            if(board[row_number][i]!='*' && isSafeMove(board,row_number,i,size)){
                board[row_number][i] = 'Q';
                number_of_ways(board,size,row_number+1,count);
                board[row_number][i] = '.';
            }
        }
    }
}

int main(){

    vector<vector<char>> board(8,vector<char>(8));
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cin>>board[i][j];
    }
    int count = 0;
    int board_size = 8;
    number_of_ways(board,board_size,0,count);
    cout<<count;


    return 0;
}