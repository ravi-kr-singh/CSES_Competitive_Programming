/*
Time limit: 1.00 s Memory limit: 512 MB
There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.

What is the maximum possible score for the first player when both players play optimally?

Input

The first input line contains an integer n: the size of the list.

The next line has n integers x1,x2,…,xn: the contents of the list.

Output

Print the maximum possible score for the first player.

Constraints
1≤n≤5000
−10^9≤xi≤10^9
Example

Input:
4
4 5 1 3

Output:
8
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long* arr = new long long[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    long long dp[n][n];
    for(int i=0;i<n;i++)
        dp[i][i] = arr[i];
    
    for(int i=0;i<n-1;i++)
        dp[i][i+1] = max(arr[i],arr[i+1]);

    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            long long x = min(arr[j]+dp[j+2][j+i],arr[j]+dp[j+1][j+i-1]);
            long long y = min(dp[j][j+i-2]+arr[j+i],dp[j+1][j+i-1]+arr[j+i]);
            dp[j][j+i] = max(x,y);
        }
    }
    //cout<<endl;
    cout<<dp[0][n-1];
    //cout<<endl<<endl;

    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(j<i){
            cout<<"\t";
        }
        else{
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    return 0;
}