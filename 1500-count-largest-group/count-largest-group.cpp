class Solution {
public:
  int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int countLargestGroup(int n) {
    unordered_map<int, int> groups;

    for (int i = 1; i <= n; ++i) {
        int sum = digitSum(i);
        groups[sum]++;
    }

    int maxSize = 0;
    for (const auto& [key, value] : groups) {
        maxSize = max(maxSize, value);
    }

    int count = 0;
    for (const auto& [key, value] : groups) {
        if (value == maxSize) {
            count++;
        }
    }

    return count;
}
};