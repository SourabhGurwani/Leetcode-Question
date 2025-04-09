class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        set<int, greater<int>> s(nums.begin(), nums.end()); // sorted descending
        vector<int> sorted_unique(s.begin(), s.end()); // convert to vector for index access

        bool check = false;
        for (int i = 0; i < sorted_unique.size(); i++) {
            if (sorted_unique[i] == k) {
                check = true;
                break;
            }
        }

        if (sorted_unique.back() < k) {  // last element (smallest) < k
            return -1;
        }

        if (!check && sorted_unique.back() > k) {
            return sorted_unique.size();
        }

        return sorted_unique.size() - 1;
    }
};
