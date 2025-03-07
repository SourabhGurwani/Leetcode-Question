class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = n - 2; i >= 0; i--) {  
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (ans[j] > 0) {
                    j += ans[j]; // Jump ahead
                } else {
                    j = n; // No warmer temperature ahead
                }
            }
            if (j < n) {
                ans[i] = j - i; // Store the difference
            }
        }

        return ans;
    }
};
