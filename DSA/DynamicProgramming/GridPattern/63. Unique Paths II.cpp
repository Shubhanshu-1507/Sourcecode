class Solution {
private:
    int SolveUsingMemo(int m,int n, int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i>=m){
            return 0;
        }

        if(j>=n){
            return 0; 
        }

        if(obstacleGrid[i][j]==1){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int answer = 0;
        int right =  SolveUsingMemo(m,n,i,j+1,obstacleGrid,dp);
        int down =  SolveUsingMemo(m,n,i+1,j,obstacleGrid,dp);     

        answer = right + down;
        dp[i][j] = answer;
        return dp[i][j];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int i=0;
    int j=0;
    return SolveUsingMemo(m,n,i,j,obstacleGrid,dp);
    }
};