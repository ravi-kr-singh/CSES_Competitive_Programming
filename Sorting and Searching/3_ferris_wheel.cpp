/*
Time limit: 1.00 s Memory limit: 512 MB
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input

The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1,p2,…,pn: the weight of each child.

Output

Print one integer: the minimum number of gondolas.

Constraints
1≤n≤2⋅10^5
1≤x≤10^9
1≤pi≤x
Example

Input:
4 10
7 2 3 9

Output:
3
*/

#include<iostream>
#include<algorithm>
using namespace std;

int min_gondolas_required(int* childWts,int& n,int& x){
    sort(childWts,childWts+n);
    int count = 0;
    int start = 0;
    int end = n - 1;
    while(end>start){
        if(childWts[end]<=x){
            if(childWts[end]+childWts[start]<=x){
                start++;
            }
            end--;
            count++;
        }
        else{
            end--;
        }
    }
    if(end == start)
        count++;
    return count;
}

int main(){
    int n,x;
    cin>>n>>x;
    int* childWeights = new int[n];
    for(int i=0;i<n;i++)
        cin>>childWeights[i];
    cout<<min_gondolas_required(childWeights,n,x);
    return 0;
}