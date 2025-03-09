class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int i=0; 
        int j=1;
        while(j<colors.size()){
            if(colors[j] == colors[j-1]){  //window only start when we get alternate.
                i=j; //window start from i 
                j++;
                continue;
            }
            
            if(j == i+k-1){ //  if window size is equal to j then shring it.
                cnt++;
                i++;
            }
            j++;

        }

        return cnt;

    }
};