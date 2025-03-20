class Solution {
public:
    void permute(vector<int> nums,vector<vector<int>> &current, vector<int> &ans,int index){
       
        if(index==nums.size()){ 
        current.push_back(ans);
        return;
        }
        ans.push_back(nums[index]);
        permute(nums,current,ans,index+1);
        ans.pop_back();
        permute(nums,current,ans,index+1);
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> current;
        vector<int> ans;
        permute(nums,current,ans,0);
        return current;
    }
};