class Solution {
public:
    string removeTrailingZeros(string num) {
        string str="";
        for(int i=num.length()-1;i>=0;i--){
            if(str.length()==0 && num[i]=='0'){
                continue;

            }else{
                str+=num[i];
            }
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};