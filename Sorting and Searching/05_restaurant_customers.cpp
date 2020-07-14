/*
Time limit: 1.00 s Memory limit: 512 MB
You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers?

Input

The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output

Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9
Example

Input:
3
5 8
2 4
3 9

Output:
2
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;



int max_customers(vector<pair<int,int>>& customerAtTimes,int& n){

    sort(customerAtTimes.begin(),customerAtTimes.end());


    int ans = 1;

    for(int i=1;i<n;i++){
        while(i<n && customerAtTimes[i].first == customerAtTimes[i-1].first){
            customerAtTimes[i].second += customerAtTimes[i-1].second;
            i++;
        }
        ans = max(ans,customerAtTimes[i-1].second);
        if(i<n){
            customerAtTimes[i].second += customerAtTimes[i-1].second;
            ans = max(ans,customerAtTimes[i].second);
        }
    }
    return ans;
    


}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> customerAtTimes(2*n);

    int j = 0;
    for(int i=0;i<n;i++){
        cin>>customerAtTimes[j].first;
        customerAtTimes[j].second = 1;
        j++;
        cin>>customerAtTimes[j].first;
        customerAtTimes[j].second = -1;
        j++;
    }
    n *=2;
    cout<<max_customers(customerAtTimes,n);

    return 0;
}

