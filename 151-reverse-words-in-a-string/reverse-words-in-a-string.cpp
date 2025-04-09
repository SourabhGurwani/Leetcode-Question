class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        // Loop through the string using index
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i]; // build the current word
            } else if (!word.empty()) {
                st.push(word); // push only non-empty words
                word = ""; // clear for next word
            }
        }

        // Push the last word if exists
        if (!word.empty()) {
            st.push(word);
        }

        // Reconstruct the reversed sentence
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }

        return result;
    }
};
