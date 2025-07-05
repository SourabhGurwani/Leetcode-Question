class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSums = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> sums(m + 1);
            for (int mask = 0; mask < (1 << m); ++mask) {
                int sum = 0, bits = 0;
                for (int i = 0; i < m; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        bits++;
                    }
                }
                sums[bits].push_back(sum);
            }
            for (int i = 0; i <= m; ++i)
                sort(sums[i].begin(), sums[i].end());
            return sums;
        };

        vector<vector<int>> leftSums = getSums(left);
        vector<vector<int>> rightSums = getSums(right);

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;
        int ans = INT_MAX;

        for (int k = 0; k <= n; ++k) {
            for (int a : leftSums[k]) {
                int rem = target - a;
                auto& rs = rightSums[n - k];
                auto it = lower_bound(rs.begin(), rs.end(), rem);
                if (it != rs.end()) {
                    int sum1 = a + *it;
                    ans = min(ans, abs(total - 2 * sum1));
                }
                if (it != rs.begin()) {
                    --it;
                    int sum2 = a + *it;
                    ans = min(ans, abs(total - 2 * sum2));
                }
            }
        }

        return ans;
    }
};
