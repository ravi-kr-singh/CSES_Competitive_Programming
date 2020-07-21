/*
Time limit: 1.00 s Memory limit: 512 MB
The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

Your task is to calculate the edit distance between two strings.

Input

The first input line has a string that contains n characters between A–Z.

The second input line has a string that contains m characters between A–Z.

Output

Print one integer: the edit distance between the strings.

Constraints
1≤n,m≤5000
Example

Input:
LOVE
MOVIE

Output:
2
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);

    int size1=str1.size();
    int size2=str2.size();

    vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));


    for(int i=size1-1;i>=0;i--){
        dp[i][size2] = size1 -i;
    }
    for(int i=size2-1;i>=0;i--){
        dp[size1][i] = size2 - i;
    }

    for(int i=size1-1;i>=0;i--){
        for(int j=size2-1;j>=0;j--){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j+1],dp[i+1][j]);
                dp[i][j] = min(dp[i][j],1+dp[i+1][j+1]);
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}