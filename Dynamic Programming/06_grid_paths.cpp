/*
Time limit: 1.00 s Memory limit: 512 MB
Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square where you only can move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.

Output

Print the number of paths modulo 109+7.

Constraints
1≤n≤1000
Example

Input:
4
....
.*..
...*
*...

Output:
3
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<long long>> dp(n,vector<long long>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }

    if(grid[n-1][n-1] == '*'){
        cout<<"0";
        return 0;
    }

    dp[n-1][n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(grid[n-1][i] != '*')
            dp[n-1][i] = dp[n-1][i+1];
    }


    for(int i=n-2;i>=0;i--){
        if(grid[i][n-1] != '*')
            dp[i][n-1] = dp[i+1][n-1];  
    }
 
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(grid[i][j] != '*')
                dp[i][j] = (dp[i][j+1] + dp[i+1][j]) % 1000000007;
        }
    }

    /*cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<dp[0][0];

    return 0;
}