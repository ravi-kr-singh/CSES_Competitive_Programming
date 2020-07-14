/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

Input

The only input line contains an integer n.

Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

Constraints
1≤n≤10^6
Example 1

Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6

Example 2

Input:
6

Output:
NO

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long sum=n;
    sum*=sum+1;
    sum/=2;
    if(sum&1)   //odd
        cout<<"NO";
    else{
        sum/=2;

        cout<<"YES\n";
        vector<vector<int>> nums(2,vector<int>(n+1,1));
        for(int i=1;i<=n;i++){
            nums[0][i]=i;
          
        }
        int i=n;
        int size=0;
        while(sum>0){
            if(i<=sum){
                nums[1][i]=0;
                sum-=i;
                i--;
            }
            else{
                nums[1][sum]=0;
                sum=0;
            }
            size++;
        }
      
        cout<<size<<endl;
        for(int i=1;i<=n;i++){
            if(nums[1][i]==0)
                cout<<i<<" ";
        }
        cout<<endl<<n-size<<endl;
        for(int i=1;i<=n;i++){
            if(nums[1][i]==1)
                cout<<i<<" ";
        }

    }


    return 0;
}