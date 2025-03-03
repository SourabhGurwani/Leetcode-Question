class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>first;
        vector<int>mid;
        vector<int> second;
        for(int x:nums){
            if(x<pivot){
                first.push_back(x);
            }
            if(x==pivot){
                mid.push_back(x);
            }
            if(x>pivot){
                second.push_back(x);
            }
        }
        vector<int> result;
        for(int x:first){
        result.push_back(x);
        }
         for(int x:mid){
        result.push_back(x);
        }
        for(int x:second){
        result.push_back(x);
        }
        return result;
    }
};