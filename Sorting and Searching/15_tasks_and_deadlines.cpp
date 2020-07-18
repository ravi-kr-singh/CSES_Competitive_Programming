/*
Time limit: 1.00 s Memory limit: 512 MB
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d−f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)

What is your maximum reward if you act optimally?

Input

The first input line has an integer n: the number of tasks.

After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.

Output

Print one integer: the maximum reward.

Constraints
1≤n≤2⋅10^5
1≤a,d≤10^6
Example

Input:
3
6 10
8 15
5 12

Output:
2
*/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> tasks(n);
    for(int i=0;i<n;i++)
        cin>>tasks[i].first>>tasks[i].second;
    sort(tasks.begin(),tasks.end()); // Shortest job first

    long long ans = 0;  
    long long finish = 0;
    for(int i=0;i<n;i++){
        finish += tasks[i].first;
        ans += tasks[i].second - finish;
    }
    cout<<ans;


    return 0;
}