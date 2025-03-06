class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1}; 

        if (nums.size() == 0) {
            return result;
        }

        int first = -1, last = -1;

        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                first = i;
                break;
            }
        }

        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                last = i;
                break;
            }
        }

        if (first != -1) {
            result[0] = first;
            result[1] = last;
        }

        return result;
    }
};
