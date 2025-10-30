class Solution {
public:
    void merge(vector<int> &nums,int left,int mid,int right){
        vector<int> temp;
        int low=left;
        int high=mid+1;
        while(low<=mid && high<=right){
            if(nums[low]<=nums[high]){
                temp.push_back(nums[low]);
                low++;
            }else{
                temp.push_back(nums[high]);
                high++;
            }
        }
        while(low<=mid){
            temp.push_back(nums[low]);
            low++;
        }
        while(high<=right){
            temp.push_back(nums[high]);
            high++;
        }
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left==right) return;
        int mid=(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int right=nums.size()-1;
        mergeSort(nums,low,right);
        return nums;
        
    }
};