/*
Time limit: 1.00 s Memory limit: 512 MB
Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.

Input

The first input line has a string of length n, and the second input line has a pattern of length m. Both of them consist of characters a–z.

Output

Print one integer: the number of occurrences.

Constraints
1≤n,m≤10^6
Example

Input:
saippuakauppias
pp

Output:
2
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str,pattern;
    cin>>str>>pattern;

    int n = str.size();
    int m = pattern.size();
    

    int* lps = new int[m]{-1};
    int j = 0;
    for(int i=1;i<m;i++){
        if(pattern[i] == pattern[j]){
            lps[i] = j;
            j++;
        }
        else{
            lps[i] = -1;
            j = 0;
        }
    }

    int i = 0;
    j = 0;
    int count = 0;
    while(i < n){
        if(j < m && str[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j == m)
                count ++;
            if(j > 0 ){
                int temp = j;
                j = lps[j-1] + 1;
                if(temp != j)
                    i--;
            }
            i++;
        }
    }

    if(j == m)
        count ++;

    cout<<count;

    return 0;
}