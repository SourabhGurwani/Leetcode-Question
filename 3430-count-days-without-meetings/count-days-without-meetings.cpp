class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        //  set<int> occupiedDays;
        
        // for (auto &meeting : meetings) { 
        //     for (int m = meeting[0]; m <= meeting[1]; m++) {
        //         occupiedDays.insert(m);
        //     }
        // }
        
        // return days - occupiedDays.size();
        sort(meetings.begin(), meetings.end());
        int ans = 0, last = 0;
        for (auto& e : meetings) {
            int st = e[0], ed = e[1];
            if (last < st) {
                ans += st - last - 1;
            }
            last = max(last, ed);
        }
        ans += days - last;
        return ans;
    }
};