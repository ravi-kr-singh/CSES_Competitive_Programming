/*
Time limit: 1.00 s Memory limit: 512 MB
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1,h2,…,hn: the price of each ticket.

The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.

Constraints
1≤n,m≤2⋅10^5
1≤hi,ti≤10^9
Example

Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> tktPrice;
    int* maxPrice = new int[m];

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        tktPrice.insert(temp);
    }
    for(int i=0;i<m;i++)
        cin>>maxPrice[i];
    

    for(int i=0;i<m;i++){
        auto it = tktPrice.upper_bound(maxPrice[i]);
        if(it == tktPrice.begin())
            cout<<"-1"<<endl;
        else{
            it--;
            cout<<(*it)<<endl;
            tktPrice.erase(it);
        }
    }
    
    
}