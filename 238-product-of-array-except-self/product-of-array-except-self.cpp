class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int product=1;
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=1;
        vector<int> suf(n);
        suf[n-1]=1;
        vector<int> ans(n);
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i-1]*pre[i-1];

        }
        for(int i=n-2;i>=0;i--){
            suf[i]=nums[i+1]*suf[i+1];
            // product=suf[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=suf[i]*pre[i];
        }
      
        return ans;
    }
};