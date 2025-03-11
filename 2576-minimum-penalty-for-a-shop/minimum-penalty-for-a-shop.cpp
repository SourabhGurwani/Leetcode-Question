class Solution {
public:
    int bestClosingTime(string customers) {
    //    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n+1, 0), suff(n+1, 0);

        // Compute prefix sum (count of 'N' before i)
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
        }

        // Compute suffix sum (count of 'Y' after i)
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        // Find the earliest minimum penalty index
        int minPenalty = suff[0];  // Closing at hour 0
        int bestHour = 0;

        for (int i = 1; i <= n; i++) {
            int penalty = pre[i - 1] + suff[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};