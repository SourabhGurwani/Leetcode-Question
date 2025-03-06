class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         #include <vector>
// using namespace std;

// vector<int> findMissingAndDuplicate(vector<vector<int>>& grid) {
    int n = grid.size();
    int N = n * n;
    
    vector<int> count(N+1,0);
    int duplicate = -1, missing = -1;
    
    // Count occurrences of each number in the grid
    for (const auto& row : grid) {
        for (int num : row) {
            count[num]++;
        }
    }
    
    // Identify the duplicate and missing number
    for (int i = 1; i <= N; i++) {
        if (count[i] == 2) duplicate = i;
        if (count[i] == 0) missing = i;
    }
    
    return {duplicate, missing};
// }

    }
};