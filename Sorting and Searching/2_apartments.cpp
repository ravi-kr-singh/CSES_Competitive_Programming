/*
Time limit: 1.00 s Memory limit: 512 MB
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input

The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

The last line contains m integers b1,b2,…,bm: the size of each apartment.

Output

Print one integer: the number of applicants who will get an apartment.

Constraints
1≤n,m≤2⋅10^5
0≤k≤10^9
1≤ai,bi≤10^9
Example

Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
*/

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int num_of_successful_applicants(int* person,int& n,int* flats,int& m,int& k){
    sort(person,person+n);
    sort(flats,flats+m);
    int ans = 0;
    int j = 0;
    int i = 0;
    while(i<m && j<n){
        if(person[j]-flats[i]>k){
            i++;
        }
        else if(person[j]-flats[i]<(-1*k)){
            j++;
        }
        else{
            i++;
            j++;
            ans++;
        }
    }
    return ans;

}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int* applicants = new int[n];
    int* apartments = new int[m];
    for(int i=0;i<n;i++)
        cin>>applicants[i];
    
    for(int i=0;i<m;i++)
        cin>>apartments[i];

    cout<<num_of_successful_applicants(applicants,n,apartments,m,k);

    return 0;
}