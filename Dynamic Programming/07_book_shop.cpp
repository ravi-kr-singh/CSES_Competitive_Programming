/*
Time limit: 1.00 s Memory limit: 512 MB
You are in a book shop which sells n different books. You know the price and number of pages of each book.

You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.

Input

The first input line contains two integers n and x: the number of books and the maximum total price.

The next line contains n integers h1,h2,…,hn: the price of each book.

The last line contains n integers s1,s2,…,sn: the number of pages of each book.

Output

Print one integer: the maximum number of pages.

Constraints
1≤n≤1000
1≤x≤10^5
1≤hi,si≤1000
Example

Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
*/ 

#include<iostream>
using namespace std;

int main(){

    int n,x;
    cin>>n>>x;
    int* price = new int[n];
    int* pages = new int[n];

    for(int i=0;i<n;i++)
        cin>>price[i];

    for(int i=0;i<n;i++)
        cin>>pages[i];
    
    int dp[n+1][x+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j == 0 || i == 0)
                dp[i][j] = 0;
            else if(price[i-1] <= j)
                dp[i][j] = max(pages[i-1]+dp[i-1][j-price[i-1]],dp[i-1][j]);
            
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][x];
    


}