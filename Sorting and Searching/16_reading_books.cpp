/*
Time limit: 1.00 s Memory limit: 512 MB
There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.

They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?

Input

The first input line has an integer n: the number of books.

The second line has n integers t1,t2,…,tn: the time required to read each book.

Output

Print one integer: the minimum total time.

Constraints
1≤n≤2⋅10^5
1≤ti≤10^9
Example

Input:
3
2 8 3

Output:
16
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* books = new int[n];
    for(int i=0;i<n;i++)
        cin>>books[i];
    


    return 0;
}