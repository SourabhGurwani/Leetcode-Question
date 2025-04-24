class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         int n = nums.size();
    unordered_set<int> totalDistinct(nums.begin(), nums.end());
    int total = totalDistinct.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> freq;
        int distinct = 0;
        for (int j = i; j < n; ++j) {
            if (freq[nums[j]] == 0) {
                distinct++;
            }
            freq[nums[j]]++;

            if (distinct == total) {
                count++;
            }
        }
    }

    return count;
    }
};