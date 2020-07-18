/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅10^5
−109≤x,ai≤10^9
Example

Input:
5 7
2 -1 3 5 -2

Output:
2
*/

#include<iostream>
#include<map>
using namespace std;

int main(){

    int n,x;
    cin>>n>>x;

    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    long long curr_sum = 0;
    long long count = 0;
    map<long long,int> freqSum;

    
    for(int i=0;i<n;i++){
        curr_sum += arr[i];

        if(curr_sum == x)
            count++;

        //if(freqSum.find(curr_sum-x) != freqSum.end())
            count += freqSum[curr_sum-x];

        freqSum[curr_sum]++;

    }


    cout<<count;

    return 0;
}