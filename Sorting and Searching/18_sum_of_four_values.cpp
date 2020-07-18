/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤1000
1≤x,ai≤10^9
Example

Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

void find_ans(vector<pair<int,int>>& arr,int& n,int& x){
    for(int i=n-1;i>2;i--){
        int sum_remaining = x - arr[i].first;
        if(sum_remaining > 0){
            for(int j=i-1;j>1;j--){  
                int sum_remaining_1 = sum_remaining - arr[j].first;
                if(sum_remaining_1 > 0){
                    int start = 0;
                    int end = j-1;
                    while(start<end){
                        if(arr[start].first + arr[end].first == sum_remaining_1){
                            cout<<arr[start].second<<" "<<arr[end].second<<" "<<arr[j].second<<" "<<arr[i].second;
                            return;
                        }
                        else if(arr[start].first + arr[end].first > sum_remaining_1)
                            end--;
                        else
                            start++;
                
                    }
                }
            }
        }
        
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());

    find_ans(arr,n,x);

    return 0;
}