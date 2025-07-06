 class Solution {
 public: 
     int func(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){

         if(ind==0){
             return (target%arr[0]==0);
         }
         if(dp[ind][target]!=-1) return dp[ind][target];
         int nottake=func(ind-1,target,arr,dp);
         int take=(arr[ind]<=target)?func(ind,target-arr[ind],arr,dp):0;
         return dp[ind][target]=take+nottake;
     }
     int change(int target, vector<int>& nums) {
         int n=nums.size();
         vector<vector<int>>dp(n,vector<int>(target+1,-1));
         return func(n-1,target,nums,dp);
     }
 };