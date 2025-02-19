class Solution {
public:
void printS(int i,vector<int> &store, vector<int> &arr, int n,vector<vector<int>> &v){
	if(i==n){
        v.push_back(store);
		return;
	}
	 store.push_back(arr[i]);
	 printS(i+1,store,arr,n,v);
	 store.pop_back();
	 printS(i+1,store,arr,n,v);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        vector<int>store;
        printS(0,store,nums,n,v);

        return v;

        
    }
};