class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsi(n, n); // Next Smaller Element index
        stack<int> st;
        
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nsi[i] = st.top();
            st.push(i);
        }

        vector<int> psi(n, -1); // Previous Smaller Element index
        stack<int> st1;
        

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
            if (!st1.empty()) psi[i] = st1.top();
            st1.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int l = arr[i];
            int b = nsi[i] - psi[i] - 1;
            int area = l * b;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};