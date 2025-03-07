class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {       
      int n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> nge_map;

        
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            nge_map[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        
        vector<int> res;
        for (int num : nums1) {
            res.push_back(nge_map[num]);
        }

        return res;
    }
};