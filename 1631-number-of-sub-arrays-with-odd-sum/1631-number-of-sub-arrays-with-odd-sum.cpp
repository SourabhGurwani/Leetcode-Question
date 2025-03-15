class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int m=1e9 + 7;
        int count=0;
        int even=1;
        int odd=0;
        int preSum=0;
        for(int i=0;i<n;i++){
            preSum+=arr[i];
            if(preSum % 2 ==0){ //odd + even=odd
                count =(count + odd) % m;
                even++;
            }
            else{ // even + odd = odd
                count = (count + even) % m;
                odd++;
            }
        }
        return count;
       


        
    }
};