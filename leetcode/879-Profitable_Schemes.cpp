class Solution {
public:
    long long dp[101][101][101];
    int MOD = (int)1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<int> tmp1, tmp2;
        for (int i = 0; i < profit.size(); i++) {
            if (profit[i] != 0) {
                tmp1.push_back(profit[i]);
                tmp2.push_back(group[i]);
            }
        }
        for (int i = 0; i < profit.size(); i++) {
            if (profit[i] == 0) {
                tmp1.push_back(0);
                tmp2.push_back(group[i]);
            }
        }
        profit = move(tmp1); group = move(tmp2);
        for (int i = 0; i < profit.size(); i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j][0] = 1;
                if (i == 0) {
                    if (j >= group[i]) {
                        dp[i][j][min(profit[i], minProfit)]++;
                    }
                    continue;
                }
                for (int k = minProfit; k >= 0; k--) {
                    // Don't use profit[i]
                    dp[i][j][k] += dp[i-1][j][k];
                    if (k == 0) dp[i][j][k] = 1;
                    // Using profit[i]
                    int p = profit[i];
                    if (j >= group[i]) {
                        int val = min(k+p, minProfit);
                        dp[i][j][val] += dp[i-1][j-group[i]][k];
                        dp[i][j][val] %= MOD;
                    }
                }
            }
        }
        return dp[profit.size()-1][n][minProfit] % MOD;
    }
};
