/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example

Input:
4 8
2 7 5 1

Output:
2 4
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for(int i=1;i<=n;i++){
        cin>>arr[i-1].first;
        arr[i-1].second = i;
    }
    sort(arr.begin(),arr.end());

    int start=0;
    int end = n-1;
    bool flag = true;
    while(end>start){
        if(arr[start].first + arr[end].first == x){
            cout<<arr[start].second<<" "<<arr[end].second;
            flag = false;
            break;
        }
        else if(arr[start].first + arr[end].first > x){
            end--;
        }
        else
            start++;
    }

    if(flag)
        cout<<"IMPOSSIBLE";
        
    return 0;
}
