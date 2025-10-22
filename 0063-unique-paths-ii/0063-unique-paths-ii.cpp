class Solution {
    int paths(int row , int col , int m , int n , vector<vector<int>>& obstacleGrid , vector<vector<int>>&dp){
        if(row >=m || col>=n || obstacleGrid[row][col]==1 )return 0;
        if(row == m-1 && col == n-1)return 1;
        if(dp[row][col] !=-1)return dp[row][col];
        int right = paths(row , col +1 , m ,n ,obstacleGrid , dp);
        int left = paths(row+1 , col , m ,n ,obstacleGrid , dp);

        return dp[row][col] = right + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m , vector<int>(n,-1));
        return paths(0 , 0 , m , n ,obstacleGrid , dp );
    }
};