class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int pc=0;
        int nc=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<0)nc++;
            else if(nums[i]==0)continue;
            else pc++;
        }
        maxi=max(maxi,max(nc,pc));
        return maxi;
    }

};