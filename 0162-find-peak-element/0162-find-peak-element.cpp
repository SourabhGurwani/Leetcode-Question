class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int idx=-1;
        if(n==1)return 0;
        // if(n==2){
        //     if(nums[0]>nums[1])return 0;
        //     else return 1;
        // }
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid==e)return mid;
            if(mid>0 && mid<n && nums[mid]> nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid+1]> nums[mid])s=mid+1;
            else e=mid-1;
            idx=mid;
        }
    return idx;
        
    }
};