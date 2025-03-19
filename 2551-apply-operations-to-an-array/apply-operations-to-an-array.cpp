class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int right=0;right<nums.size()-1;right++){
            if(nums[right]==nums[right+1]){
                nums[right]=nums[right]*2;
                nums[right+1]=0;
            }
        }
        vector<int> result(nums.size(),0);
        int i=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]>0){
                result[i]=nums[right];
                i++;
            }

        }
        return result;
        
    }
};