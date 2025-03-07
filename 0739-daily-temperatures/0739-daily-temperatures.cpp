class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n,0);
        stack<int>st;
        int c=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()]){
                st.pop();
                c++;
            }
            if(!st.empty()){
                ans[i]=st.top()-i;
            }
            st.push(i);
            c=0;
        }
        return ans;

        
    }
};