class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < col; j++) {
            int no1s = 0;
            int no0s = 0;
            for (int i = 0; i < row; i++) {
                if (grid[i][j] == 0)
                    no0s++;
                else
                    no1s++;
            }
            if (no0s > no1s) {
                for (int i = 0; i < row; i++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < row; i++) {
            int x = 1;
            for (int j = col - 1; j >= 0; j--) {
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};