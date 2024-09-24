class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;

        //1> pivot idx(change )
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){ // if array is already greater e.g=> 321 -> 123
            reverse(nums.begin(),nums.end());
            return;
        }
        // 2> sort/reverse after pivot idex 
        reverse(nums.begin()+(idx+1),nums.end());

        // 3> finding just greater number than idx
        int j=-1;
        for(int i=idx+1;i<n;i++){
           if( nums[i]>nums[idx]){
           j=i;
           break;
           }
        }

        // 4> swap pivot idx and j;

        int temp=nums[idx];
        nums[idx]= nums[j];
        nums[j]=temp;

        return ;
    }
};