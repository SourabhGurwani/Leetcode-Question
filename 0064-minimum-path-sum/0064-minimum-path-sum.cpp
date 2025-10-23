class Solution {
    int helper(int i , int j , vector<vector<int>>& grid,vector<vector<int>>&dp , int row , int col){
        if(i>=row || j>=col) return 1e9;
        if(i==row-1 && j==col-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int right = grid[i][j] + helper(i, j+1 , grid , dp , row , col);
        int down = grid[i][j] + helper(i+1, j , grid , dp , row , col);

        return dp[i][j] = min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return helper(0 , 0 ,grid , dp , row , col );

    }
};