/*
Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example

Input:
3 11
1 5 7

Output:
3
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minimum_coins(int sum,int* coins,int* dp,vector<bool>& isVisited,int& n){
    

    if(isVisited[sum])
        return dp[sum];
    
    dp[sum] = INT_MAX;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(sum-coins[i] < 0){
            break;
        }
        int temp = minimum_coins(sum-coins[i],coins,dp,isVisited,n);
        if(temp != -1){
            dp[sum] = min(dp[sum],1+temp);
            flag = false;
        }
    }
    isVisited[sum] = true;
    if(flag)
        dp[sum] = -1;
    return dp[sum];
}

int main(){
    int n,x;
    cin>>n>>x;
    int* coins = new int[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins,coins+n);;
    int* dp = new int[x+1];
    dp[0] = 0;
    vector<bool> isVisited(x+1,false);
    isVisited[0] = true;
    cout<<minimum_coins(x,coins,dp,isVisited,n);

    return 0;
}