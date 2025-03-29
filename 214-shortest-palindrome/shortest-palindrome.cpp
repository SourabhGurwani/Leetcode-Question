class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        int n = combined.size();
        vector<int> lps(n, 0);

        // Compute LPS (Longest Prefix Suffix) for KMP
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && combined[i] != combined[j])
                j = lps[j - 1];

            if (combined[i] == combined[j])
                j++;

            lps[i] = j;
        }

        int palindromeLength = lps[n - 1]; // Longest palindrome prefix length
        string suffix = s.substr(palindromeLength); // Non-palindromic suffix
        reverse(suffix.begin(), suffix.end());

        return suffix + s; // Prepend reversed suffix
    }
};
