class Solution {
public:
    bool isValid(string s) {
           stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char ch : s) {
            if (mapping.find(ch) != mapping.end()) { // If it's a closing bracket
                if (st.empty() || st.top() != mapping[ch]) 
                    return false;
                st.pop(); // Matching pair found, remove from stack
            } else {
                st.push(ch); // Open bracket, push to stack
            }
        }

        return st.empty();
        
    }
};