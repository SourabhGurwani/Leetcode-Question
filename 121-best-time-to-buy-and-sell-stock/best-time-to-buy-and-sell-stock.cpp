class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxi(prices.size(),0);
        maxi[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],prices[i]);
        }
        for(int i=0;i<prices.size();i++){
            maxi[i]=maxi[i]-prices[i];
        }
        sort(maxi.begin(),maxi.end());
        return maxi[prices.size()-1];
        
    }
};