class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0;
        int lo = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (lo > prices[i]) {
                lo = prices[i];
            } else {
                int prof = prices[i] - lo - fee;
                if (prof > 0) {
                    ans += prof;
                    lo = prices[i] - fee;
                }
            }
        }
        return ans;
    }
};
