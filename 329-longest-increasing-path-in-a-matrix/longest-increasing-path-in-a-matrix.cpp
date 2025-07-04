class Solution {
public:
    int Increase(vector<vector<int>> &matrix, int x, int y, vector<vector<int>>& dp1) {
        int row = matrix.size();
        int col = matrix[0].size();

        if (x < 0 || y < 0 || x >= col || y >= row)
            return 0;

        if (dp1[y][x] != -1)
            return dp1[y][x];

        int maxPath = 1;

        // Move Right
        if (x + 1 < col && matrix[y][x + 1] > matrix[y][x])
            maxPath = max(maxPath, 1 + Increase(matrix, x + 1, y, dp1));

        // Move Down
        if (y + 1 < row && matrix[y + 1][x] > matrix[y][x])
            maxPath = max(maxPath, 1 + Increase(matrix, x, y + 1, dp1));

        // Move Left
        if (x - 1 >= 0 && matrix[y][x - 1] > matrix[y][x])
            maxPath = max(maxPath, 1 + Increase(matrix, x - 1, y, dp1));

        // Move Up
        if (y - 1 >= 0 && matrix[y - 1][x] > matrix[y][x])
            maxPath = max(maxPath, 1 + Increase(matrix, x, y - 1, dp1));

        return dp1[y][x] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp1(row, vector<int>(col, -1));
        int result = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result = max(result, Increase(matrix, j, i, dp1));
            }
        }

        return result;
    }
};
