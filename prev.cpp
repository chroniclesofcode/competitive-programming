class Solution {
public:
    int dp[101][101];
    int strangePrinter(string s) {
        int n = s.size();
        int chars[26];
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                int res = dp[i][j-1] + 1;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        res = min(res, dp[i][k] + dp[k+1][j-1]);
                    }
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};
