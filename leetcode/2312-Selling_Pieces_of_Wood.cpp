class Solution {
public:
    unordered_map<long long, unordered_map<long long, long long>> price;
    long long dp[202][202];
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for (auto e : prices) {
            price[e[0]][e[1]] = max(price[e[0]][e[1]], (long long)e[2]);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = price[i][j];
                for (int k = 1; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][j-k]+dp[i][k]);
                }
                for (int k = 1; k <= i; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-k][j]+dp[k][j]);
                }
            }
        }
        return dp[m][n];
    }
};
