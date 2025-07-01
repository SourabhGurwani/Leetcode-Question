class Solution {
public:
    
    int maxLootWayOne(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int steal=nums[idx]+maxLootWayOne(nums,idx+2,dp);
        int skip=maxLootWayOne(nums,idx+1,dp);

        return dp[idx]=max(steal,skip);
        

    }
    int maxLootWayTwo(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int steal=nums[idx]+maxLootWayTwo(nums,idx+2,dp);
        int skip=maxLootWayTwo(nums,idx+1,dp);

        return dp[idx]=max(steal,skip);
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp1;
        vector<int> dp2;
         if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        dp1.resize(nums.size(),-1);
        dp2.resize(nums.size(),-1);
        return max(maxLootWayOne(nums,0,dp1),maxLootWayTwo(nums,1,dp2));


        
    }
};