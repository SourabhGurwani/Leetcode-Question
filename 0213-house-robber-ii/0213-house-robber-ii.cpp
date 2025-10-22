class Solution {
    int maxAmt(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + maxAmt(idx + 2, nums, dp);
        int nonpick = maxAmt(idx + 1, nums, dp);

        return dp[idx] = max(pick, nonpick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n - 1; i++) temp1.push_back(nums[i]);
        for (int i = 1; i < n; i++) temp2.push_back(nums[i]);

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int ans1 = maxAmt(0, temp1, dp1);
        int ans2 = maxAmt(0, temp2, dp2);

        return max(ans1, ans2);
    }
};
