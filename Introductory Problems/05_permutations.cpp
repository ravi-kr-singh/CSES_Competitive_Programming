/*
Time limit: 1.00 s Memory limit: 512 MB
A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation exists.

Input

The only input line contains an integer n.

Output

Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤10^6
Example 1

Input:
5

Output:
4 2 5 3 1

Example 2

Input:
3

Output:
NO SOLUTION

*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1)
        cout<<n;
    else if(n<4)
        cout<<"NO SOLUTION";
    else if(n==4){
        cout<<"2 4 1 3";
    }
    else{
        int* arr=new int[n];
        int i=0;
        int t=1;
        while(i<n){
            arr[i]=t;
            t++;
            i+=2;
        }
        i=1;
        while(i<n){
            arr[i]=t;
            t++;
            i+=2;
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }

    return 0;
}