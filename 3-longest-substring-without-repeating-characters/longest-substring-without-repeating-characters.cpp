class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        else{
            unordered_set<int> set;
            int count=INT_MIN;
            int l=0;
            for(int i=0;i<s.length();i++){
                if(set.find(s[i])!=set.end()){
                    while(l<i && set.find(s[i])!=set.end()){
                        set.erase(s[l]);
                        l++;
                    }

                }
                set.insert(s[i]);
                count=max(count,i-l+1);
            }
            return count;
        }
    }
};