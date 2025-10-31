class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        vector<int> freq(nums.size(),0);
        for(int num:nums){
            freq[num]++;
        }
        for(int s=0;s<freq.size();s++){
            if(freq[s]==2){
                result.push_back(s);
            }
        }
        return result;
        
    }
};