class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int coins = 0;
        int inf = (int)1e9;
        vector<array<int,2>> dp(n);
        // dp[i][0] = min cost to buy this fruit
        // dp[i][1] = min cost to not buy this fruit
        dp[0][0] = prices[0];
        dp[0][1] = inf;
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + prices[i];
            dp[i][1] = inf;
            for (int j = i-1; 2*(j+1) >= (i+1); j--) {
                dp[i][1] = min(dp[i][1], dp[j][0]);
            }
        }
        
        return min(dp[n-1][0], dp[n-1][1]);
    }
};
