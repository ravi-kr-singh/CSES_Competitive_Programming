/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7
*/

#include<iostream>
#include<stack>
#include<utility>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    stack<pair<int,int>> store;
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    
   
    for(int i=0;i<n;i++){
        while(!store.empty() && store.top().first >= arr[i].first )
            store.pop();
        if(store.empty())
            cout<<"0 ";
        else
            cout<<store.top().second<<" ";
        store.push(arr[i]);
    }
    
    return 0;
}