/*
Time limit: 1.00 s Memory limit: 512 MB
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9
Example

Input:
3
3 5
4 9
5 8

Output:
2
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

bool compf(pair<int,int> a ,pair<int,int> b){
    if(a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}

int max_movies(vector<pair<int,int>>& timings,int& n){
    sort(timings.begin(),timings.end(),compf);

    int count = 1;
    int temp = timings[0].second;
    for(int i=1;i<n;i++){
        if(timings[i].first>= temp){
            count ++ ;
            temp = timings[i].second;
        }
    }
    return count;
    
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> timings(n);
    for(int i=0;i<n;i++){
        cin>>timings[i].first>>timings[i].second;
    }
    cout<<max_movies(timings,n);

    return 0;
}