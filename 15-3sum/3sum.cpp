class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        vector<vector<int>> out;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values for i

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    out.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for left & right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;  // Move to next element
                    right--;
                } 
                else if (sum < 0) {
                    left++;  // Increase sum
                } 
                else {
                    right--; // Decrease sum
                }
            }
        }
        return out;
    }
};