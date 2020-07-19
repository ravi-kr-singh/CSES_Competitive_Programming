/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.

Input

The first input line has an integer n: the size of the array.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅10^5
−109≤ai≤10^9
Example

Input:
5
3 1 2 7 4

Output:
1
*/

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<long long,int> freqSum;
    
    long long curr_sum = 0;
    long long count = 0;

    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        
        int remainder = ((curr_sum % n) + n) % n;

        if(remainder == 0)
            count++;
        
        count += freqSum[remainder];

        freqSum[remainder]++;
        
    }
    cout<<count<<endl;
    return 0;
}