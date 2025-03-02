class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int a:nums){
            cout<<a;
        }
        
    }
};