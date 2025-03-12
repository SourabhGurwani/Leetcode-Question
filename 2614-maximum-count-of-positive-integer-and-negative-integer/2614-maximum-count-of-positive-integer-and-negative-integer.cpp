class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
    int s=0;
    int e=n-1;
    int pos=0;
    int neg=0;
    while(s <= e){
        int mid=s+(e-s)/2;
        if(nums[mid]<0){
            neg=mid+1;
             s=mid+1;
        }
        else{
            e=mid-1;
        }  
    }
    s=0;
    e=n-1;
     while(s <= e){
        int mid=s+(e-s)/2;
        if(nums[mid]>0){
            pos=n-mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }  
    }
    int ans=max(pos,neg);
    return ans;
    }

};