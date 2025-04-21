class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long min_val = 0, max_val = 0;
        long sum = 0;

        for (int diff : differences) {
            sum += diff;
            min_val = min(min_val, sum);
            max_val = max(max_val, sum);
        }

        long range = upper - lower;
        long valid_start_values = range - (max_val - min_val) + 1;

        return max(0L, valid_start_values);
    }
};
