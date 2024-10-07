class Solution {
private:
    int SolveUsingmemo(string& a,string& b, int i,int j,vector<vector<int>>& dp){
        if(i>=a.length()|| j>=b.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(a[i]==b[j]){ans=1+SolveUsingmemo(a,b,i+1,j+1,dp);}
        else{
            ans = 0+ max(SolveUsingmemo(a,b,i+1,j,dp),SolveUsingmemo(a,b,i,j+1,dp));
        }

        dp[i][j]=ans;
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        int i=0;
        int j=0;

        return SolveUsingmemo(text1,text2,i,j,dp);
    }
};
