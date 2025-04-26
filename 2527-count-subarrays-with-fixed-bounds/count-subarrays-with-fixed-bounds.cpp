class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long ans = 0;
    int last_minK = -1, last_maxK = -1, last_out_of_bounds = -1;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < minK || nums[i] > maxK) {
            last_out_of_bounds = i;
        }
        if (nums[i] == minK) {
            last_minK = i;
        }
        if (nums[i] == maxK) {
            last_maxK = i;
        }
        int valid_start = min(last_minK, last_maxK);
        if (valid_start > last_out_of_bounds) {
            ans += valid_start - last_out_of_bounds;
        }
    }
    
    return ans;
    }
};