/*
Time limit: 1.00 s Memory limit: 512 MB
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

Output

For each test, print "YES" if you can empty the piles and "NO" otherwise.

Constraints
1≤t≤10^5
0≤a,b≤10^9
Example

Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES

*/

#include<iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        /*
            x is the total number of moves--> 2 from A and 1 from B.
            y is the total number of moves--> 2 from B and 1 from A.
            Therefore,
            a = 2x + y
            b = x + 2y
            On solving for x and y,
            x = (2a - b)/3;
            y = (2b - a)/3;
            if x and y comes out to be integer then answer is YES
            otherwise no;
        */

        if((2*a-b)>=0 && (2*a-b)%3==0 && (2*b-a)>=0 && (2*b-a)%3==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }


    return 0;
}