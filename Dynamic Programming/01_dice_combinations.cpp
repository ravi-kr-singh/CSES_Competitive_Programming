/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input

The only input line has an integer n.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n≤10^6
Example

Input:
3

Output:
4
*/

#include<iostream>
#include<vector>
using namespace std;

int find_ways(int i,int* dp){
    if(i<0)
        return 0;
    if(dp[i]!=0)
        return dp[i];
    else{
        dp[i] = 0;
        for(int j=1;j<=6;j++){
            dp[i] += find_ways(i-j,dp);
            dp[i] = dp[i] % 1000000007;
        }
        return dp[i];

    }
}

int main(){
    int n;
    cin>>n;
    int* dp = new int[n+1]{1};
    cout<<find_ways(n,dp);

}