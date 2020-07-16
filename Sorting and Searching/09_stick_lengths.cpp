/*
Time limit: 1.00 s Memory limit: 512 MB
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

What is the minimum total cost?

Input

The first input line contains an integer n: the number of sticks.

Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

Output

Print one integer: the minimum total cost.

Constraints
1≤n≤2⋅10^5
1≤pi≤10^9
Example

Input:
5
2 3 1 5 2

Output:
5
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    nth_element(arr,arr+n/2,arr+n);  // Linear Time

    int temp = arr[n/2];
    //cout<<temp<<endl;
    long long ans = 0;
    for(int i=0;i<n;i++)
        ans += abs(temp-arr[i]);
    
    cout<<ans<<endl;



    return 0;
}