class Solution {
public:
int helper(int idx , vector<int>& coins , int amount,vector<vector<int>>&dp ){
    if(idx==coins.size()-1){
        if(amount % coins[idx] == 0) return amount/coins[idx];
        return 1e9;
    }
    if(dp[idx][amount] != -1)return dp[idx][amount];
    int notTake= helper(idx+1 , coins, amount,dp);
    int take = 1e9;
    if(amount>= coins[idx]){
        take = 1 + helper(idx  , coins , amount- coins[idx],dp);
    }
    return dp[idx][amount] =  min(take , notTake);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1 , -1));
        int x=  helper(0 , coins , amount,dp);
        if(x!= 1e9)return x;
        else return -1;
    }
};