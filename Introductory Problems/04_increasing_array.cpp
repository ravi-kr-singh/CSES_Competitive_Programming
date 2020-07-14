/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

On each turn, you may increase the value of any element by one. What is the minimum number of turns required?

Input

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print the minimum number of turns.

Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
5
3 2 5 1 7

Output:
5

*/

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    long long ans=0;
    int big=arr[0];
    
    for(int i=1;i<n;i++){
        big=max(big,arr[i]);
        ans+=big-arr[i];
    }
    cout<<ans;
    return 0;
}