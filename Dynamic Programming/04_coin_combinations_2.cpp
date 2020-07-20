/*
Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
 
For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
2+2+5
3+3+3
2+2+2+3
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
3
*/
 
#include<iostream>
using namespace std;
 
int distinct_ways(int* coins, int n, int sum){
    int dp[sum+1]{0}; 
    dp[0] = 1; 
    for(int i=0;i<n;i++) 
        for(int j=coins[i];j<=sum;j++){
            dp[j] += dp[j-coins[i]]; 
            dp[j] %= 1000000007;
        }
    return dp[sum]; 
}
 
int main(){
    int n,x;
    cin>>n>>x;
    int* coins = new int[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];
    cout<<distinct_ways(coins,n,x);
    
 
   
    return 0;
}