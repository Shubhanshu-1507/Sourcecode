/*
There is a robot on an m x n grid. 
The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible
unique paths that the robot can take to reach the bottom-right corner.
*/

class Solution {
private:
    int SolveUsingMemo(int m, int n,int i, int j,vector<vector<int>>& dp){
        if(i>=m){
            return 0;
        }

        if(j>=n){
            return 0; 
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int answer = 0;
        int right =  SolveUsingMemo(m,n,i,j+1,dp);
        int down =  SolveUsingMemo(m,n,i+1,j,dp);     

        answer = right + down;
        dp[i][j] = answer;
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        int i = 0;
        int j=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return SolveUsingMemo(m,n,i,j,dp);
    }
};