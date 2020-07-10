/*
Time limit: 1.00 s Memory limit: 512 MB
Given a string, your task is to generate all different strings that can be created using its characters.

Input

The only input line has a string of length n. Each character is between a–z.

Output

First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.

Constraints
1≤n≤8
Example

Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int factorial(int n){
    if(n==0 || n==1)
        return 1;
    return n*factorial(n-1);
}
 
int main(){
    string str;
    getline(cin,str);
    int n=str.size();
    int* freq=new int[26]{0};
    for(int i=0;i<n;i++)
        freq[str[i]-97]++;
    int count=factorial(n);
    for(int i=0;i<26;i++){
        if(freq[i]>1)
            count/=factorial(freq[i]);
    }
    sort(str.begin(),str.end());
    cout<<count<<endl<<str<<endl;
  
    while(next_permutation(str.begin(),str.end()))
        cout<<str<<endl;
  
 
    return 0;
}