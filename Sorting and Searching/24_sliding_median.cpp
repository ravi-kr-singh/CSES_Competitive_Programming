/*
You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.

The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.

Input

The first input line contains two integers n and k: the number of elements and the size of the window.

Then there are n integers x1,x2,…,xn: the contents of the array.

Output

Print n−k+1 values: the medians.

Constraints
1≤k≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
8 3
2 4 3 5 8 1 2 1

Output:
3 4 5 5 2 1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> window(k);
    vector<int> tempWindow;
    for(int i=0;i<k;i++)
        window[i] = arr[i];

    tempWindow = window;
    int median;
    for(int i=k;i<n;i++){
  
        nth_element(window.begin(),window.begin()+k/2,window.end());
        if(k%2 ==0){
            
            nth_element(window.begin(),window.begin()+k/2 -1,window.end());
            median = (window[k/2]+window[k/2-1])/2;
        }
        else
            median = window[k/2];
        cout<<median<<" ";
        tempWindow.erase(window.begin());
        tempWindow.push_back(arr[i]);
        window = tempWindow;
    }
 
    nth_element(window.begin(),window.begin()+k/2,window.end());
    if(k%2 ==0){
        
        nth_element(window.begin(),window.begin()+k/2 -1,window.end());
        median = (window[k/2]+window[k/2-1])/2;
    }
    else
        median = window[k/2];
    cout<<median<<" ";


    return 0;
}