class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
            sort(nums.begin(),nums.end());
            vector<int> result;
            for(int i=0;i<queries.size();i++){
                int sum=0;
                int put=0;
                for(int j=0;j<nums.size();j++){
                    // int m=sum+nums[j+1];
                    if(queries[i]>=nums[j] ){
                        
                        sum=sum+nums[j];
                        if(sum<=queries[i]){
                        put++;
                        }
                    }
                    else{
                        
                        break;}
                        
                    
                }
                result.push_back(put);

            }
            return result;
        
    }
};