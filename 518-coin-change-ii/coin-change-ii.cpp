class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] = number of ways to make amount 'i'
        // vector<int> dp(amount + 1, 0);
        bool allEven = all_of(coins.begin(), coins.end(), [](int c) {
            return c % 2 == 0;
        });
        if (allEven && amount % 2 == 1) return 0;
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;  // base case: 1 way to make amount 0 (use no coins)

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return (int)dp[amount];
    }
};
