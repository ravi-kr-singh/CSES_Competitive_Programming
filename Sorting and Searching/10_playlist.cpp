/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?

Input

The first input line contains an integer n: the number of songs.

The next line has n integers k1,k2,…,kn: the id number of each song.

Output

Print the length of the longest sequence of unique songs.

Constraints
1≤n≤2⋅10^5
1≤ki≤10^9
Example

Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/

#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;

int freq_of_num(int& element,multiset<int>& set_sorted){
    auto itLow = set_sorted.lower_bound(element);
    if(itLow == set_sorted.end())
        return 0;
    auto itHigh = set_sorted.upper_bound(element);
    return distance(itLow,itHigh);

}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    multiset<int> set_sorted;
  
    for(int i=0;i<n;i++)
        cin>>arr[i];
    

    int left = 0;
    int right = 0;
    int ans = 1;
    while(left<n && right<n){

        if(freq_of_num(arr[right],set_sorted) == 0){
            set_sorted.insert(arr[right]);
            right++;        
        }
        else{
            ans = max(right-left,ans);
            set_sorted.erase(arr[left]);
            left++;
        }
    }
    ans = max(right-left,ans);
    cout<<ans;



    return 0;
}
