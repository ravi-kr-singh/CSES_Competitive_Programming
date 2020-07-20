/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an integer n. On each step, you may substract from it any one-digit number that appears in it.

How many steps are required to make the number equal to 0?

Input

The only input line has an integer n.

Output

Print one integer: the minimum number of steps.

Constraints
1≤n≤10^6
Example

Input:
27

Output:
5

Explanation: An optimal solution is 27→20→18→10→9→0
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int min_steps_required(int n,vector<int>& dp){
    if(dp[n]!=-1)
        return dp[n];
    
    int digit = INT_MIN;
    for(int i=n;i>0;i/=10)
        digit = max(digit,i%10);
    
    dp[n] = 1+min_steps_required(n-digit,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    cout<<min_steps_required(n,dp);

    return 0;
}