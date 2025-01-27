class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
          int maxCand= *max_element(candies.begin(),candies.end());
        vector<bool> result;
        for(int can : candies){
            if(can + extraCandies>=maxCand){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};