class Solution {
public:
    int hold[100001][101];
    int free[100001][101];
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        hold[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (free[i-1][j-1] > 0 || j == 1) {
                    hold[i][j] = max(hold[i-1][j], free[i-1][j-1] - prices[i]);
                    free[i][j] = max(free[i-1][j], hold[i-1][j] + prices[i]);
                } else {
                    if (i+1 < n) {
                        hold[i][j] = -prices[i+1];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, free[n-1][i]);
        }
        return ans;
    }
};
