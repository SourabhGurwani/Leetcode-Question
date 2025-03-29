class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
                set<int> s(nums.begin(), nums.end()); // Ordered unique elements
        int index = 0;

        for (int num : s) { // Copy back to nums
            nums[index++] = num;
        }

        return s.size(); // Return new size
    }
        
    
};