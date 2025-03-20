class Solution {
//     struct VectorHash {
//     size_t operator()(const vector<int>& vec) const {
//         size_t hashValue = vec.size();
//         for (int num : vec) {
//             hashValue ^= hash<int>{}(num) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
//         }
//         return hashValue;
//     }
// };
public:
    void permute(vector<int> &nums,set <vector<int>> &curr,int index){
        if(index==nums.size()){
            curr.insert(nums);

        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permute(nums,curr,index+1);
            swap(nums[i],nums[index]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set <vector<int>> curr;
        permute(nums,curr,0);
        return vector<vector<int>> (curr.begin(),curr.end());
        
    }
};