#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
private:
    int SolveUsingMemo(string a, string b, int i, int j,vector<vector <int>>& dp){
        if(j==b.length()){
            return a.length()-i;
        }
         if(i==a.length()){
            return b.length()-j;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i]==b[j]){
            ans = 0+ SolveUsingMemo(a,b,i+1,j+1,dp);
        }
        else{
            int replace = 1+ SolveUsingMemo(a,b,i+1,j+1,dp);
            int del = 1+ SolveUsingMemo(a,b,i+1,j,dp);
            int insert = 1+ SolveUsingMemo(a,b,i,j+1,dp);

            ans = min(replace,min(del,insert));
        }

        dp[i][j]=ans;
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector <int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));

        int i=0;
        int j=0;

        return SolveUsingMemo(word1,word2,i,j,dp);
    }
};
