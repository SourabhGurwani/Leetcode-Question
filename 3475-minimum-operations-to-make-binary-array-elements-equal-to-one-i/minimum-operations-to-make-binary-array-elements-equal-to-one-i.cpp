class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int right=0;right<nums.size()-2;right++){
            while(nums[right]==0){
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
        sort(nums.begin(),nums.end());
        if(nums[0]==0){
            count=-1;
            
        }
        return count;
        
    }
};