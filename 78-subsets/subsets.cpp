class Solution {
public:
    // void helper(vector<int>& nums,int index,vector<int>& subset,vector<vector<int>>& result){
    //     if(index==nums.size()){
    //         result.push_back(subset);
    //         return;
    //     }
    //     subset.push_back(nums[index]);
    //     helper(nums,index+1,subset,result);
    //     subset.pop_back();
    //     helper(nums,index+1,subset,result);
        


    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> result;
        // vector<int> subset;
        // helper(nums,0,subset,result);
        // return result;

        // with dp

    vector<vector<int>> dp={{}};
    for(int num:nums){
        int n=dp.size();
        for(int i=0;i<n;i++){
            vector<int> subset=dp[i];
            subset.push_back(num);
            dp.push_back(subset);

        }
        
    }
    return dp;

    
    }  
    
};