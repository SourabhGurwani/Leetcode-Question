class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n2 = nums2.size();
        vector<int> nge(n2, -1);
        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums2[i]); 
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    nums1[i] = nge[j];
                    break;
                }
            }
        }

        return nums1;





        
    }
};