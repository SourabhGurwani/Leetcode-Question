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
       
        for(int i=1;i<=n-k;i++){
            int fin=0;
            for(int j=i;j<k+i;j++){
                if(grumpy[j]==1){
                    fin+=customers[j];
                }
               
            }
             if (fin>max){
                    max=fin;
                }
          
       

        }
        return initialSum+max;

    }
};