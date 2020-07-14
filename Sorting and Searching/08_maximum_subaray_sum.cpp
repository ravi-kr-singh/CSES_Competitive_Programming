/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅10^5
−10^9≤xi≤10^9
Example

Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    long long ans = arr[0];
    long long temp = arr[0];
    for(int i=1;i<n;i++){
        long long num = arr[i];
        temp = max(num,num+temp);
        ans = max(ans,temp);
    }
    cout<<ans;

    return 0;
}
