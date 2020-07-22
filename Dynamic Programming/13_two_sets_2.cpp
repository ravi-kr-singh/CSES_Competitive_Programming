/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.
 
For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}
Input
 
The only input line contains an integer n.
 
Output
 
Print the answer modulo 10^9+7.
 
Constraints
1≤n≤500
Example
 
Input:
7
 
Output:
4
*/
 
#include<iostream>
#include<vector>
using namespace std;
 
int number_of_ways(int i,int sum1,vector<vector<int>>& dp,int& n, int& s){
 
    if(sum1 == s)
        return 1;   
 
    if(i > n || sum1 >s)
        return 0;
    
 
    if(dp[i][sum1]!= -1)
        return dp[i][sum1];
 
   
    dp[i][sum1] = number_of_ways(i+1,sum1+i,dp,n,s);
 
    dp[i][sum1] += number_of_ways(i+1,sum1,dp,n,s);
    dp[i][sum1] %= 1000000007;
   
    return dp[i][sum1];
 
}
 
int main(){
    int n;
    cin>>n;
    int s = (n*(n+1))/2;
    if(s&1){
        cout<<0;
    }
    else{
        s /= 2;
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        long long temp = number_of_ways(1,0,dp,n,s);
        long long inverse = 500000004;  // MMMI(Modular Multiplicative inverse) of 2 in 10^9+7 
        long long answer = (temp * inverse) % 1000000007;
        cout<<answer;
    }
    
 
    return 0;
}