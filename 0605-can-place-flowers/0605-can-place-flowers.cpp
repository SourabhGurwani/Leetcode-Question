class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N=flowerbed.size();
        int count=0;
        if(n == 0)return true;

        if(N==1){
            if(flowerbed[0]==0)return true;
            return false;
        }else if(N == 2){
            if(n==1){
            if(flowerbed[0]==1 || flowerbed[1]==1)return false;
            return true;
            }
            else{
                return false;
            }
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            count++;
            flowerbed[0]=1;
            }
        if(flowerbed[N-1]==0 && flowerbed[N-2]==0){
            count++;
            flowerbed[N-1]=1;
        }

        for(int i=1;i<N-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else continue;
        }
        if(count>=n)return true;
        return false;
        
    }
};