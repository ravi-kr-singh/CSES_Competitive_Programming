/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a string of length n and a dictionary containing k words. In how many ways can you create the string using the words?
 
Input
 
The first input line has a string containing n characters between a–z.
 
The second line has an integer k: the number of words in the dictionary.
 
Finally there are k lines describing the words. Each word is unique and consists of characters a–z.
 
Output
 
Print the number of ways modulo 109+7.
 
Constraints
1≤n≤5000
1≤k≤10^5
the total length of the words is at most 106
Example
 
Input:
ababc
4
ab
abab
c
cb
 
Output:
2
 
Explanation: The possible ways are ab+ab+c and abab+c.
*/
 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 
bool isValidWordforString(string& a,string& b,int index){
    
    for(int i=0;i<a.size();i++){
        if(a[i] != b[index])
            return false;
        index ++;
    }
    return true;
}
 
int number_of_ways(vector<string>& words,int& k,int index,string& str,vector<int>& dp){
 
    if(dp[index]!= -1)
        return dp[index];
 
    dp[index] = 0 ;
    for(int i=0;i<k;i++){
        if(words[i].size() > (str.size()-index))
            break;
        if(isValidWordforString(words[i],str,index)){
            dp[index] += number_of_ways(words,k,index+words[i].size(),str,dp);
            dp[index] %= 1000000007;
        }
    }
    return dp[index];
 
}

bool compf(string& a,string& b){
    return a.size()<b.size();
}
 
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    vector<string> words(k);
    vector<int> dp(str.size()+1,-1);
    dp[str.size()] = 1;
    for(int i=0;i<k;i++)
        cin>>words[i];
    sort(words.begin(),words.end(),compf);
    cout<<number_of_ways(words,k,0,str,dp);
 
 
 
}