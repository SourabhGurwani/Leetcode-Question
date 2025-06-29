/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left=0;
    let right=height.length-1;
    let maxi=0;
    while(left<right){
        let min=Math.min(height[left],height[right])
        let w=right-left;
        maxi=Math.max(maxi,min*w);
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }


    }
    return maxi;
    
};