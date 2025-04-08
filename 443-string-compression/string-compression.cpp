class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, index = 0;
        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;

            // Count how many times current char repeats
            while (i < chars.size() && chars[i] == current) {
                i++;
                count++;
            }

            // Write the character
            chars[index++] = current;

            // Write the count if > 1
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};
