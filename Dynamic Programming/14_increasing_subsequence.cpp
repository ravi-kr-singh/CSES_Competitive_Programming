/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.

A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.

Input

The first line contains an integer n: the size of the array.

After this there are n integers x1,x2,…,xn: the contents of the array.

Output

Print the length of the longest increasing subsequence.

Constraints
1≤n≤2⋅105
1≤xi≤10^9
Example

Input:
8
7 3 5 3 6 2 9 8

Output:
4
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    dp[0] = 1;
    int ans = 1;
    for(int i=1;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j]>=dp[i])
                dp[i] = dp[j] + 1;
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<" ";

    return 0;
}