class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> per;
        for(int i=0;i<n;i++){
            per.push_back('(');
        }
        for(int i=0;i<n;i++){
            per.push_back(')');
        }
        vector<string> str;
        do{
            string m(per.begin(),per.end());
            str.push_back(m);
            
        }while(next_permutation(per.begin(),per.end()));
        vector<string> str1;
        for(string x:str){
            stack<char> s;
            for(int i=0;i<x.length();i++){
                if(x[i]=='('){
                    s.push('(');
                }
                if(s.empty()){
                    continue;
                }
                char top = s.top();
                if(x[i]==')'&& top=='('){
                    s.pop();
                }
            }
            if(s.empty()){
                str1.push_back(x);
            }
           
        }
        return str1;
        
    }
};