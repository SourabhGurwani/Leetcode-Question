class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
        int right=s.length()-1;
        int count=0;
        // if(s.length()==1) return 1;
        while(right>=0 && string(1,s[right])!=" "){
            count++;
            right--;

        }
         return count;
    }
};