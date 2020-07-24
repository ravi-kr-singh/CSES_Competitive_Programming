/*
Time limit: 1.00 s Memory limit: 512 MB
There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.

What is the maximum amount of money you can earn?

Input

The first input line contains an integer n: the number of projects.

After this, there are n lines. Each such line has three integers ai, bi, and pi: the starting day, the ending day, and the reward.

Output

Print one integer: the maximum amount of money you can earn.

Constraints
1≤n≤2⋅105
1≤ai≤bi≤10^9
1≤pi≤10^9
Example

Input:
4
2 4 4
3 6 6
6 8 2
5 7 3

Output:
7
*/

#include<iostream>
#include<vector>
using namespace std;

struct triplet{
    int start;
    int end;
    int reward;

    triplet(){
        
    }
    triplet(int a,int b,int c){
        start = a;
        end = b;
        reward = c;
    }
    void input(int a,int b,int c){
        start = a;
        end = b;
        reward = c;
    }

};

int main(){
    int n;
    cin>>n;

    /*vector<triplet> projects(n);
    for(int i=0;i<n;i++)
        cin>>projects[i].start>>projects[i].end>>projects[i].reward;*/

    triplet temp;
    temp.input(1,2,3);
    cout<<endl<<temp.start<<" "<<temp.end<<" "<<temp.reward;
    
    

    return 0;
}