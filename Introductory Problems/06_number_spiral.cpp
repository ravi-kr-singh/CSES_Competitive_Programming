/*
Time limit: 1.00 s Memory limit: 512 MB
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

        1   2   9   10  25
        4   3   8   11  24
        5   6   7   12  23
        16  15  14  13  22
        17  18  19  20  21

Your task is to find out the number in row y and column x.

Input

The first input line contains an integer t: the number of tests.

After this, there are t lines, each containing integers y and x.

Output

For each test, print the number in row y and column x.

Constraints
1≤t≤10^5
1≤y,x≤10^9
Example

Input:
3
2 3
1 1
4 2

Output:
8
1
15

*/

#include<iostream>
using namespace std;

long long find_number(long long& row,long long& col){
        long long t=max(row,col)-1;
        long long lower_limit=(t*t)+1;
        long long upper_limit=(t+1)*(t+1); 

        if(row>=col){
                   
                if(row&1)   //odd numbered L shaped
                        return lower_limit+col-1;
                return upper_limit-col+1;
        }
        else{
              
                if(col&1)   //odd numbered L shaped
                        return upper_limit-row+1;
                return lower_limit+row-1;
        }

        
}


int main(){

        int t;
        cin>>t;
        while(t--){
                long long y,x;
                cin>>y>>x;
                cout<<find_number(y,x)<<endl;

        }
        
        // Printing 5*5 matrix
        /*cout<<endl<<endl;
        for(int i=1;i<6;i++){
                for(int j=1;j<6;j++)
                        cout<<find_number(i,j)<<" ";
                cout<<endl;
        }
        */



        return 0;
}