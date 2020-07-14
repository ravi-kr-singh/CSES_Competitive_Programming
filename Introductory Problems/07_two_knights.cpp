/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

Input

The only input line contains an integer n.

Output

Print n integers: the results.

Constraints
1≤n≤10000
Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848

*/

#include<iostream>
using namespace std;

int m=0;
int f=0;

long long number_of_ways(long long t){
    long long total_ways=(t*(t-1))/2;
    long long ans=total_ways-(8*f);    
    m++;
    f+=m;
    return ans;

}

int main(){
    int n;
    cin>>n;
    cout<<0<<endl;
    for(int i=2;i<=n;i++){
        cout<<number_of_ways(i*i)<<endl;
    }

    return 0;
}