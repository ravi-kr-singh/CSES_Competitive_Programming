/*

Time limit: 1.00 s Memory limit: 512 MB
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

Input

The only input line contains a string of n characters.

Output

Print one integer: the length of the longest repetition.

Constraints
1≤n≤10^6
Example

Input:
ATTCGGGA

Output:
3

*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string sequence;
    getline(cin,sequence);

    int ans=1;
    int temp=1;
    for(int i=1;i<sequence.size();i++){
        if(sequence[i]==sequence[i-1])
            temp++;
        else{
            ans=max(ans,temp);
            temp=1;
        }
    }
    ans=max(ans,temp);
    cout<<ans;

    return 0;
}