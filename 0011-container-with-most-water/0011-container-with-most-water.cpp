class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area=0;
        while(i<=j){
            int a=min(height[i],height[j]);
            area=max(a*(j-i),area);
            if(height[i]>=height[j]){
                j--;
            }
            else{
                i++;
            }
        
        }
        return area;
        
        
    }
};