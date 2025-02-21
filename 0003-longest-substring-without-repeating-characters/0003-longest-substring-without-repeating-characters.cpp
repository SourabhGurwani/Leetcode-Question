// class Solution {
// public:
//     bool isvalid(string &str){
//         set<char> s;
//         for(int i=0; i<str.size(); i++){
//             s.insert(str[i]);
//         }
//         if(s.size() == str.size()) return true;
//         return false;
//     }
//     int lengthOfLongestSubstring(string s) {
//         int n=s.length();
//         int maxi = 0;
//         for(int i=0;i<n;i++){
//             string str =  "";
//            for(int j=i; j<n; j++){
//                 str+=s[j];
//                 if(isvalid(str)){
//                     int x = str.size();
//                     maxi = max(x,maxi);
//                 }else break;
//            }
//         }
//         return maxi;
//     }
// };



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxi = 0;
    for(int j=0; j<s.size(); j++){
        set<char> st;
        for(int i=j; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                break;
            }
        
            st.insert(s[i]);
            int size = st.size();
            maxi = max(maxi, size);

        }
    }
        return maxi;
    }
};