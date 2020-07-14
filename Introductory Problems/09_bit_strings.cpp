/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

The only input line has an integer n.

Output

Print the result modulo 10^9+7.

Constraints
1≤n≤10^6
Example

Input:
3

Output:
8

*/

#include<iostream>
using namespace std;

#define Limit 1000000007

long long find_ans(int n){
    if(n==0)
        return 1;
    
    long long ans=find_ans(n/2);
    ans*=ans;
    ans%=Limit;
    if(n&1){
        ans*=2;
        ans%=Limit;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<find_ans(n);

    return 0;
}