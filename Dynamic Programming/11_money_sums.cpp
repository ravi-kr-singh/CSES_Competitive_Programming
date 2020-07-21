/*
Time limit: 1.00 s Memory limit: 512 MB
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Input

The first input line has an integer n: the number of coins.

The next line has n integers x1,x2,…,xn: the values of the coins.

Output

First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

Constraints
1≤n≤100
1≤xi≤1000
Example

Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
*/

#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* coins = new int[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];
    
    set<int> answer;

    answer.insert(coins[0]);
  
    for(int j=1;j<n;j++){
        vector<int> temp(answer.size());
        int i=0;
        for(auto it=answer.begin();it!=answer.end();it++){
            temp[i] = coins[j]+(*it);
            i++;
        }
        for(i=0;i<temp.size();i++)
            answer.insert(temp[i]);
        answer.insert(coins[j]);
    }
    cout<<answer.size()<<endl;
    for(auto it=answer.begin();it!=answer.end();it++)
        cout<<(*it)<<" ";

    return 0;
}