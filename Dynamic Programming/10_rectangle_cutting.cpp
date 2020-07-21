/*
Time limit: 1.00 s Memory limit: 512 MB
Given an a×b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
 
Input
 
The only input line has two integers a and b.
 
Output
 
Print one integer: the minimum number of moves.
 
Constraints
1≤a,b≤500
Example
 
Input:
3 5
 
Output:
3
*/
 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
int main(){
    int a,b;
    cin>>a>>b;
    if(a>b){
        int temp = a;
        a = b;
        b = temp;
    }
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
 
    
 
    dp[1][1] = 0;
 
 
    for(int i=2;i<=b;i++)
        dp[1][i] = i-1;
 
    for(int i=2;i<=a;i++){
        for(int j=i+1;j<=b;j++){
            dp[i][j] = INT_MAX;
            for(int k=1;k<i;k++)
                dp[i][j] =  min(dp[i][j] ,1+dp[min(k,j)][max(k,j)]+dp[i-k][j]);
            for(int k=1;k<j;k++)
                dp[i][j] = min(dp[i][j] , 1+dp[min(i,k)][max(i,k)]+dp[min(i,j-k)][max(i,j-k)]);
            
        }
    }
    /*cout<<endl;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    
    cout<<dp[a][b];
 
  
    return 0;
}