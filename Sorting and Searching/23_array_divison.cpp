/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

Input

The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.

The next line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print one integer: the maximum sum in a subarray in the optimal division.

Constraints
1≤n≤2⋅10^5
1≤k≤n
1≤xi≤10^9
Example

Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. The largest sum is the last sum 8.
*/

#include<iostream>
using namespace std;


bool isSolutionPossible(long long& mid,int* arr,int& n,int& k){

    int count = 1;
    long long curr_sum = 0;
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(arr[i] > mid)
            return false;
        if(curr_sum > mid){
            count ++;
            curr_sum = arr[i];
            if(count > k)
                return false;
        }           
    }
    return true;

}

long long divide_array_optimally(int* arr,int& n,int& k,long long& start,long long& end){

    long long maxSum = end;
    while(start<=end){
        long long mid = start + (end - start)/2;
        if(isSolutionPossible(mid,arr,n,k)){
            end = mid - 1;
            maxSum = mid;
        }
        else{
            start = mid + 1;
        }

    }
    return maxSum;
}

int main(){
    int n,k;
    cin>>n>>k;

    int* arr = new int[n];
    long long min_element = 1;
    long long max_element = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_element += arr[i];
    }
    
    cout<<divide_array_optimally(arr,n,k,min_element,max_element);

    return 0;
}