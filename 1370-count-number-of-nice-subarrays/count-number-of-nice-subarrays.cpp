
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int left = 0, count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            k -= (nums[right] % 2);  // Decrease k when encountering an odd number
            
            while (k < 0) {  // Shrink the window if k becomes negative
                k += (nums[left] % 2);
                left++;
            }
            
            count += (right - left + 1);  // Count valid subarrays
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};