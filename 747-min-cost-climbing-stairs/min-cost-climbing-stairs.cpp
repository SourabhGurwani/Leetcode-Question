class Solution {
public:
    int minCost(vector<int>& cost,int idx,vector<int>& dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        
        return dp[idx]=cost[idx]+min(minCost(cost,idx+1,dp),minCost(cost,idx+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.resize(cost.size(),-1);
        return min(minCost(cost,0,dp),minCost(cost,1,dp));
        
    }
};