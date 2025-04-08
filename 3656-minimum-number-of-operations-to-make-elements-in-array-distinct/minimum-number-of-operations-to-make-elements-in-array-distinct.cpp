class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(*max_element(nums.begin(),nums.end())+1,0);
        for(int n: nums){
            freq[n]++;
        }
        int count=0;
        while(*max_element(freq.begin(),freq.end())>1 ){
           for(int i=0;i<3;i++){
            freq[nums[0]]--;
            nums.erase(nums.begin());
           }
           count++;

        }
        return count;

    }
};