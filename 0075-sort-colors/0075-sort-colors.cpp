void sort01(vector<int>&nums){
    int n=nums.size();
    int no0s=0;
    int no1s=0;
    int no2s=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)no0s++;
        else if(nums[i]==1)no1s++;
        else no2s++;
    }
    int start1=0+no0s;
    int end1=no0s+no1s;

    for(int i=0;i<n;i++){
        if(i<no0s)nums[i]=0;
        else if(i>=start1 && i<end1)nums[i]=1;
        else nums[i]=2;
    }


}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort01(nums);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        
    }
};