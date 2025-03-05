class Solution {
public:
    long long coloredCells(int n) {
        long long N=n;
        if(N==1)return 1;
        return 1+4*(N*(N-1)/2);
        
    }
};