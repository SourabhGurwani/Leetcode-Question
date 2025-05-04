class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
         unordered_map<int, int> count;
        int result = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            // Normalize the pair so that smaller number is always first
            int key = min(a, b) * 10 + max(a, b);
            result += count[key]++;
        }

        return result;
    }
};