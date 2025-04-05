class Solution {
public:
void dfs(vector<int>& nums, int index, int currentXOR, int& total) {
    if (index == nums.size()) {
        total += currentXOR;
        return;
    }

    // Include nums[index] in the XOR
    dfs(nums, index + 1, currentXOR ^ nums[index], total);

    // Exclude nums[index] from the XOR
    dfs(nums, index + 1, currentXOR, total);
}

int subsetXORSum(vector<int>& nums) {
    int total = 0;
    dfs(nums, 0, 0, total);
    return total;
}
};