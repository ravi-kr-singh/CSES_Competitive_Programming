/*
Time limit: 1.00 s Memory limit: 512 MB
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

Input

The first input line has an integer n: the number of apples.

The next line has n integers p1,p2,…,pn: the weight of each apple.

Output

Print one integer: the minimum difference between the weights of the groups.

Constraints
1≤n≤20
1≤pi≤109
Example

Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include<iostream>
#include<cmath>
using namespace std;

long long min_difference(int* arr,int size,long long sum){
    int limit = pow(2,size);
    long long ans = sum;
    for(int i=1;i<limit-1;i++){
        int temp = i;
        long long sum1 = 0;
        long long sum2 = 0;
        for(int j=size-1;j>=0;j--){
            int t = temp&1;
            if(t == 1){
                sum1 += arr[j];
            }
            else{
                sum2 += arr[j];
            }
            temp /= 2;
        }
        ans = min(ans,abs(sum1-sum2));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<min_difference(arr,n,sum);


}