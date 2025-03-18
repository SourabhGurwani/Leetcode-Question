class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int count=1;
        int left=0;
        int bitMask=0;
        int maxi=0;
        for(int right=0;right<nums.size();right++){
           while((bitMask & nums[right])!=0){
             bitMask^=nums[left];
             left++;
           }
           bitMask |=nums[right];
           maxi=max(maxi,right-left+1);
        }
        
        return maxi;
    }
};