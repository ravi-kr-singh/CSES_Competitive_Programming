/*
Time limit: 1.00 s Memory limit: 512 MB
There is a street of length x whose positions are numbered 0,1,…,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

Your task is to calculate the length of the longest passage without traffic lights after each addition.

Input

The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.

Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights. Each position is distinct.

Output

Print the length of the longest passage without traffic lights after each addition.

Constraints
1≤x≤10^9
1≤n≤2⋅10^5
0<pi<x
Example

Input:
8 3
3 6 2

Output:
5 3 3
*/

#include<iostream>
#include<set>
#include<climits>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<int> maxDistances;
    maxDistances.insert(x);


    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        lights.insert(pos);
        
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        it2--;
        auto currentLightPos = it2;
        it2--;
        int temp = (*it1)-(*it2);
        auto distIterator = maxDistances.lower_bound(temp);
        maxDistances.erase(distIterator);
        maxDistances.insert((*currentLightPos)-(*it2));
        maxDistances.insert((*it1)-(*currentLightPos));
        cout<<(*maxDistances.rbegin())<<" ";     
        
    }
    


    return 0;
}