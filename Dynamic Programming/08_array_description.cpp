/*
Time limit: 1.00 s Memory limit: 512 MB
You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

Input

The first input line has two integers n and m: the array size and the upper bound for each value.

The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

Output

Print one integer: the number of arrays modulo 109+7.

Constraints
1≤n≤10^5
1≤m≤100
0≤xi≤m
Example

Input:
3 5
2 0 2

Output:
3

Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.
*/

#include<iostream>
#include<vector>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    if(arr[n-1] == 0){
        for(int i=0;i<m;i++)
            dp[n-1][i] = 1;
    }
    else
        dp[n-1][arr[n-1]-1] = 1;
    
    for(int i=n-2;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(arr[i] == j+1 || arr[i] == 0){
                if(j-1 >= 0){
                    dp[i][j] += dp[i+1][j-1];
                    dp[i][j] %= 1000000007;
                }
                if(j+1 < m){
                    dp[i][j] += dp[i+1][j+1];
                    dp[i][j] %= 1000000007;
                }
                dp[i][j] += dp[i+1][j];
                dp[i][j] %= 1000000007;
            }
        }
    }
    int arr_count = 0;
    if(arr[0] == 0){
        for(int i=0;i<m;i++){
            arr_count += dp[0][i];
            arr_count %= 1000000007;
        }
    }
    else
        arr_count = dp[0][arr[0]-1];
    
    cout<<arr_count;
    /*cout<<endl<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;
    }
    */
    return 0;
}