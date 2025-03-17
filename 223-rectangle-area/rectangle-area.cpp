class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
         int slen = max(0, min(ax2, bx2) - max(ax1, bx1));
        int sbrea = max(0, min(ay2, by2) - max(ay1, by1));
        int alen=abs(ax1-ax2);
        int abrea=abs(ay1-ay2);
        int blen=abs(bx1-bx2);
        int bbrea=abs(by1-by2);
        int area1=(alen*abrea)-(slen*sbrea);
        int area2=(blen*bbrea)-(slen*sbrea);
        return (slen * sbrea)+area1+area2;
        
    }
};