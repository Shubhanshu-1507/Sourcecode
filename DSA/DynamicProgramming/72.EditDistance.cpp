/**
 * Problem Description:
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 * - Insert a character
 * - Delete a character
 * - Replace a character
 *
 *
 * Example:
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * Therefore, the minimum number of operations required is 3.
 */

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

// Complexity
// Time Complexity:
// The time complexity is (O(m \times n)), where (m) and (n) are the lengths of word1 and word2, respectively. This is because each subproblem is solved only once and stored in the dp table.

// Space Complexity:
// The space complexity is (O(m \times n)) due to the 2D array dp used for memoization.