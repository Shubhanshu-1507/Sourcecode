/**
 * Calculates the length of the longest common subsequence between two strings.
 *
 * @param text1 The first string.
 * @param text2 The second string.
 * @return The length of the longest common subsequence.
 *
*/

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

//  *This function uses dynamic programming to solve the problem. It creates a 2D array to store the lengths of the longest common subsequences between prefixes of the two input strings. It iterates through the strings and compares characters at each position. If the characters match, it increments the length of the longest common subsequence by 1. If the characters don't match, it takes the maximum length from the previous positions. Finally, it returns the length of the longest common subsequence.

//  * The time complexity of this function is O(m * n), where m and n are the lengths of the input strings. The space complexity is also O(m * n) as it uses a 2D array to store the lengths of the longest common subsequences.
