class Solution {
public:
 const int MOD = 1000000007;
    int helper(int idx, int n, int x,vector<vector<int>>& dp) {
        int val = pow(idx, x);
        if (val > n) return 0; 
        if (val == n) return 1;
        if(dp[idx][n]!=-1)return dp[idx][n];
        int take =helper(idx + 1, n - val, x,dp);
        int skip =helper(idx + 1, n, x,dp);

    
        return dp[idx][n] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1, n, x,dp);
    }
};
