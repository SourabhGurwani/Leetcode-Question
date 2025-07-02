class Solution {
public:
    void helper(vector<int>& nums,int index,vector<int>& subset,vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        helper(nums,index+1,subset,result);
        subset.pop_back();
        helper(nums,index+1,subset,result);
        


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        helper(nums,0,subset,result);
        return result;
        
    }
};