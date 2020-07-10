/*
Time limit: 1.00 s Memory limit: 512 MB
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤10^6
Example

Input:
AAAACACBA

Output:
AACABACAA
*/

#include<iostream>
#include<string>
using namespace std;

string find_palindrome(int* freq){
    string ans;
    char middle_element;
    bool flag = true;
    for(int i=0;i<26;i++){
        if ((freq[i]&1) && flag){
            middle_element = i + 'A';
            flag = false;
            freq[i]--;
        }
        else if (freq[i]&1)
            return "NO SOLUTION";

        while(freq[i]>0){
            ans.push_back(i+'A');
            freq[i] -= 2;
        }
        
    }
    string final_ans = ans;
    if(!flag)
        final_ans.push_back(middle_element);
    for(int i=ans.size()-1;i>=0;i--)
        final_ans.push_back(ans[i]);
    return final_ans;
}

int main(){

    string str;
    getline(cin,str);
    int* arr = new int[26]{0};
    for(int i=0;i<str.size();i++){
        arr[str[i]-'A']++;
    }
    cout<<find_palindrome(arr);

}