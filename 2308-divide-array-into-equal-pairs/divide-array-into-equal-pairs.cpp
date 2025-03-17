class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        bool result=true;
        for(int i=0;i<nums.size();i=i+2){
            if(nums[i]!=nums[i+1]){
                result= false;
            }
        }
        return result;
    }
};