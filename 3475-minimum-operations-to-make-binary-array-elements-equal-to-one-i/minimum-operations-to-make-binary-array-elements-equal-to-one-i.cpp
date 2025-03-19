class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int right=0;right<nums.size()-2;right++){
            if(nums[right]==0){
                nums[right]=1;
                if(nums[right+1]==1){
                    nums[right+1]=0;
                }
                else{
                    nums[right+1]=1;
                }
                if(nums[right+2]==1){
                    nums[right+2]=0;
                }
                else{
                    nums[right+2]=1;
                }
                count++;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return -1;
            
        }
        return count;
        
    }
};