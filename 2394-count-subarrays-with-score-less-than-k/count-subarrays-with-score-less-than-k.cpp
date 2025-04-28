class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
           long long ans = 0;
        long long total = 0;
        int n = nums.size();
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            total += nums[r];
            
            while (l <= r && total * (r - l + 1) >= k) {
                total -= nums[l];
                ++l;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};