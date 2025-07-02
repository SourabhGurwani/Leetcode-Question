class Solution {
public:
    int path(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int x, int y, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (x == m - 1) return grid[x][y];  // Last row: only grid value

        if (dp[x][y] != -1) return dp[x][y];

        int minCost = INT_MAX;
        for (int nextCol = 0; nextCol < n; ++nextCol) {
            int move = moveCost[grid[x][y]][nextCol];  // cost from current cell value to nextCol
            int subCost = path(grid, moveCost, x + 1, nextCol, dp);
            minCost = min(minCost, move + subCost);
        }

        return dp[x][y] = grid[x][y] + minCost;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            int a = path(grid, moveCost, 0, j, dp);  // Start from top row
            ans = min(ans, a);
        }

        return ans;
    }
};
