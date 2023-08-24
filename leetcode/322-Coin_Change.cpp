class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, (long long)INT_MAX+20);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount] < INT_MAX ? dp[amount] : -1);
    }
};
