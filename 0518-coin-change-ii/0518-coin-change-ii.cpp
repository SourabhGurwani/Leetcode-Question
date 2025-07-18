class Solution {
public:
int helper(int idx , int amount, vector<int>& coins , vector<vector<int>> &dp){
    if(amount==0)return 1;
    if(idx==coins.size())return 0;
    if(dp[idx][amount]!=-1)return dp[idx][amount];
    int nonTake =  helper(idx+1,amount,coins,dp);
    int take=0;
    if(amount >= coins[idx]){
        take =helper(idx, amount - coins[idx], coins,dp);
    }

    return dp[idx][amount]  =  take + nonTake;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0 ,amount,coins,dp);
    }
};