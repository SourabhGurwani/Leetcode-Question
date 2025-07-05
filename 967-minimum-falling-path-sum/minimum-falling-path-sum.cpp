class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[n-1];  // last row

        for(int i = n-2; i >= 0; --i){
            vector<int> curr(n);
            for(int j = 0; j < n; ++j){
                int down = prev[j];
                int leftDiag = (j > 0) ? prev[j-1] : INT_MAX;
                int rightDiag = (j < n-1) ? prev[j+1] : INT_MAX;
                curr[j] = matrix[i][j] + min({down, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
