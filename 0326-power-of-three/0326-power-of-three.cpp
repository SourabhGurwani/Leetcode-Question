class Solution {
private:
    bool helper(long long val, int n) {
        if (val == n) return true;
        if (val > n) return false;
        return helper(val * 3, n);
    }
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return helper(1, n);
    }
};
