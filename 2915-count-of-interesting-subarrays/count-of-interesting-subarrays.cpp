class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
          unordered_map<int, long long> prefixCount;
    prefixCount[0] = 1; // Base case
    long long result = 0;
    int prefixSum = 0;

    for (int num : nums) {
        if (num % modulo == k) {
            prefixSum += 1;
        }
        int target = (prefixSum - k) % modulo;
        if (target < 0) target += modulo; // handle negative mod

        result += prefixCount[target];
        prefixCount[prefixSum % modulo]++;
    }

    return result;
    }
};