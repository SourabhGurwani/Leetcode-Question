class Solution {
public:
    int maxArea(vector<int>& height) {
        // int maxheight=height[0];
        // for(int i=1;i<height.size()-1;i++){
        //     maxheight=max(maxheight,height[i]);

        // }
        int maxArea=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int minArea=min(height[left],height[right]);
            maxArea=max(maxArea,minArea*(right-left));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
        
    }
};