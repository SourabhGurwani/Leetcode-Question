class Solution {
public:
    int path(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row >= rows || col >= cols) return INT_MAX;

        if (row == rows - 1 && col == cols - 1) return grid[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int down = path(grid, row + 1, col, dp);
        int right = path(grid, row, col + 1, dp);

        return dp[row][col] = grid[row][col] + min(down, right);
    }

    int minPathSum(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return path(grid, 0, 0, dp);
    }
};
