class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort children by greed
        sort(s.begin(), s.end()); // sort cookies by size

        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                child++; // give this cookie to this child
            }
            cookie++; // move to next cookie regardless
        }

        return child; // number of content children
    }
};
