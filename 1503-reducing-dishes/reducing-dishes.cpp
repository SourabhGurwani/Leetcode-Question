class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        int maxi=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<n;i++){
            int max=0;
            int count=1;
            for(int j=i;j<n;j++){
                max=max+satisfaction[j]*count;
                count++;

            }
            if(max>maxi){
                maxi=max;
            }
        }
        return maxi;
        
    }
};