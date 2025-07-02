class Solution {
public:
    int step(int n,vector<int>& dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=step(n-1,dp)+step(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp;
        dp.resize(n+1,-1);
        return step(n,dp);
        
    }
};