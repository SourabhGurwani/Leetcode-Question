class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int c=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')c++;
        }
        if(c==0)return 0;
        int i=1;
        int j=k;
        int mini=c;
        while(j<n){
            
            if(blocks[i-1]=='W'){
                if(c>1)c=c-1;  
            }
            c=0;
            for(int a=i;a<=j;a++){
                if(blocks[a]=='W')c++;
            }
            
            
            mini=min(c,mini);
            i++;
            j++;
        }
        return mini;

        
    }
};