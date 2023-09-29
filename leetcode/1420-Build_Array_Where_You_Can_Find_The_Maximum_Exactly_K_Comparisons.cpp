class Solution {
public:
    #define ll long long
    ll dp[51][101][101];
    int numOfArrays(int n, int m, int sc) {
        if (m < sc) return 0;
        if (sc == 0) return 0;
        ll MD = (int)1e9 + 7;
        // For 0..i, max used j, numchanges k
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= min(i,sc); k++) {
                    if (i == 1) {
                        dp[i][j][k] = 1;
                        break;
                    }
                    dp[i][j][k] = dp[i-1][j][k] * j;
                    for (int l = 1; l < j; l++) {
                        dp[i][j][k] += dp[i-1][l][k-1];
                    }
                    dp[i][j][k] %= MD;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += dp[n][i][sc];
        }
        return ans % MD;
    }
};
