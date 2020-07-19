/*
Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example

Input:
3 9
2 3 5

Output:
8
*/

#include<iostream>
#include<algorithm>
using namespace std;

long long number_of_ways(int sum,int* coins,int& n,long long* dp,bool* isVisited){

    if(isVisited[sum])
        return dp[sum];
    
    dp[sum] = 0;
    for(int i=0;i<n;i++){
        if(sum-coins[i] < 0)
            break;
        dp[sum] += number_of_ways(sum-coins[i],coins,n,dp,isVisited);
        dp[sum] %= 1000000007;
    }
    isVisited[sum] = true;
    return dp[sum];

}


int main(){
    int n,x;
    cin>>n>>x;
    int* coins = new int[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];

    sort(coins,coins+n);

    long long* dp = new long long[x+1];
    bool* isVisited = new bool[x+1]{false};

    dp[0] = 1;
    isVisited[0] = true;
    cout<<number_of_ways(x,coins,n,dp,isVisited);


    return 0;
}