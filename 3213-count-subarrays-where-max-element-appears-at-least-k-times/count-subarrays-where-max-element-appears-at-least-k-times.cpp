class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0;
        long long ans = 0;
        int max_val = *max_element(nums.begin(), nums.end());
        int count_max = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;
            if (nums[right] == max_val)
                count_max++;

            while (count_max >= k) {
                ans += (n - right); 
                freq[nums[left]]--;
                if (nums[left] == max_val && freq[nums[left]] < k)
                    count_max--;
                left++;
            }
        }

        return ans;
    }
};