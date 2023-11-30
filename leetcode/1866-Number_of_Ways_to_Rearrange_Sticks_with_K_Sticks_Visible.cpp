class Solution {
public:
    long long dp[1001][1001];
    const int md = (int)1e9 + 7;
    int rearrangeSticks(int n, int k) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= i+1; j++) {
                if (j == i+1) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] += (i) * dp[i-1][j];
                dp[i][j] %= md;
            }
        }
        return dp[n-1][k];
    }
};
