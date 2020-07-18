/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example

Input:
5 7
2 4 1 2 7

Output:
3
*/

#include<iostream>

using namespace std;

int main(){

    int n,x;
    cin>>n>>x;

    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int curr_sum = 0;
    int left = 0;
    int right = -1;
    int count = 0;
    while(left<n && right <n){
        if(curr_sum < x){
            right ++;
            if(right < n)
                curr_sum += arr[right];
          
        }
        else if(curr_sum > x){
            curr_sum -= arr[left];
            left ++;
        }
        else{
            count ++;
            right ++;
            curr_sum -= arr[left];
            if(right < n)
                curr_sum += arr[right];
            left++;
            
        }
    }


    cout<<count;

    return 0;
}