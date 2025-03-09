class Solution {
public:
    bool isAnagram(string s, string t) {
        bool result=true;
        vector<int> str(26,0);
        vector<int> str1(26,0);
        for(int i=0;i<s.length();i++){
            str[s[i]-'a']++;

        }
          for(int i=0;i<t.length();i++){
            str1[t[i]-'a']++;

        }
        for(int i=0;i<str.size();i++){
            if(str[i]!=str1[i]){
                result =false;
            }
        }
        return result;
        
    }
};