class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k=minutes;
        int n=customers.size();
        int initialSum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                initialSum+=customers[i];
            }
        }
        int extraSum=0;
        
        for(int i=0;i<k;i++){
            if(grumpy[i]==1){
                extraSum+=customers[i];

            }
        }
        int max=extraSum;
       
        for(int i=k;i<n;i++){
            if(grumpy[i]==1){
                extraSum+=customers[i];
            }
            if(grumpy[i-k]==1){
                extraSum-=customers[i-k];
            }
            if(max<extraSum){
                max=extraSum;
            }
          
       

        }
        return initialSum+max;

    }
};