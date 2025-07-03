class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        total /= 2;

        unordered_set<int> sum = {0};
        for (int num : nums) {
            vector<int> curr(sum.begin(), sum.end());
            for (int s : curr) {
                int newsum = s + num;
                if (newsum == total) return true;
                sum.insert(newsum);
            }
        }

        return sum.count(total);
    }
};
