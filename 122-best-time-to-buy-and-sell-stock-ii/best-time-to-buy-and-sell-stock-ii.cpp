class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int n=prices.size();
        vector<int>dp(n,0);
        for(int i=0;i<=n;i++){
            if(i+1<=n-1){
                dp[i]=prices[i+1]-prices[i];
            }

        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(dp[i]>0){
                sum=sum+dp[i];
            }
        }
        return sum;
        
    }
};