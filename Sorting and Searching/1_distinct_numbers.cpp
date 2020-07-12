/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input

The first input line has an integer n: the number of values.

The second line has n integers x1,x2,…,xn.

Output

Print one integers: the number of distinct values.

Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
5
2 3 2 2 3

Output:
2
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    
    int count = 1;
    int i = 1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1])
            i++;
        if(i==n)
            break;
        count++;
        i++;
    }

    cout<<count;

    return 0;
}