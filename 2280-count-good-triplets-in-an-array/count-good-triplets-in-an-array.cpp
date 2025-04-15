class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> indexInNums2(n);
        
        // Map each value to its index in nums2
        for (int i = 0; i < n; ++i) {
            indexInNums2[nums2[i]] = i;
        }
        
        // Map nums1 into indices from nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = indexInNums2[nums1[i]];
        }
        
        // Use BIT to count increasing subsequences
        vector<int> leftCount(n), rightCount(n);
        
        FenwickTree leftBIT(n), rightBIT(n);
        
        // Count how many elements before i are smaller
        for (int i = 0; i < n; ++i) {
            leftCount[i] = leftBIT.query(mapped[i]);
            leftBIT.update(mapped[i], 1);
        }
        
        // Count how many elements after i are greater
        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = rightBIT.query(n - 1) - rightBIT.query(mapped[i]);
            rightBIT.update(mapped[i], 1);
        }
        
        // Total good triplets
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += (long long)leftCount[i] * rightCount[i];
        }
        
        return result;
    }

private:
    class FenwickTree {
    public:
        FenwickTree(int size): bit(size + 1, 0), n(size) {}
        
        void update(int i, int delta) {
            for (++i; i <= n; i += i & -i)
                bit[i] += delta;
        }
        
        int query(int i) {
            int sum = 0;
            for (++i; i > 0; i -= i & -i)
                sum += bit[i];
            return sum;
        }
    private:
        vector<int> bit;
        int n;
    };
};
