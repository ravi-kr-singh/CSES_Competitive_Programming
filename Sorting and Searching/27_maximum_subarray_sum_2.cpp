/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.

Input

The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅10^5
1≤a≤b≤n
−10^9≤xi≤10^9
Example

Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Output:
8
*/

#include<iostream>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int start = 0;
    long long local_sum = 0;
    long long max_sum = 0;
    for(int i=0;i<n;i++){
        int length = i-start+1;
        if(length < a){
            local_sum += arr[i];
        }
        else if(length > b){
            local_sum += arr[i];
            local_sum -= arr[start];
            start ++;
            if(length>=a && length <=b)
                    max_sum = max(max_sum,local_sum);
        }
        else{
            if(arr[i]+local_sum >= arr[i]){
                local_sum += arr[i];
                max_sum = max(max_sum,local_sum);
            }
            else{
                local_sum = arr[i];
                start = i;
                length = i-start+1;
                if(length>=a && length <=b)
                    max_sum = max(max_sum,local_sum);
            }
        }
 
        
    }
    cout<<max_sum;
    return 0;
}