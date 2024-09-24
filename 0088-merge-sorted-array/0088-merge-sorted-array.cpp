class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the last index of nums1 and nums2
        int i = m - 1; // Last element in nums1's initialized portion
        int j = n - 1; // Last element in nums2
        int k = m + n - 1; // Last index of merged array
        
        // Merge from the end of the arrays to the beginning
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy elements from nums1 since they are already in place
        
        // Optional: Print the merged array
        for (int i = 0; i < m + n; i++) {
            cout << nums1[i] << " ";
        }
        cout << endl;
    }
};
