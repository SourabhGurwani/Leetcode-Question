class Solution {
public:
    int maxLoot(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int steal=nums[idx]+maxLoot(nums,idx+2,dp);
        int skip=maxLoot(nums,idx+1,dp);
        dp[idx]=max(steal,skip);
        return dp[idx];

    }
    int rob(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size(),-1);
        return maxLoot(nums,0,dp);

        
    }
};