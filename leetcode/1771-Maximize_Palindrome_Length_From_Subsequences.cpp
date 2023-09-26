class Solution {
public:
    int dp[2003][2003];
    int longestPalindrome(string a, string b) {
        string s = a + b;
        int n = s.size();
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j == i) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = max(dp[i+1][j], j > 0 ? dp[i][j-1] : dp[i+1][j]);
                if (s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
                    if (j >= a.size() && i < a.size()) {
                        ans = max(ans, dp[i+1][j-1] + 2);
                    }
                }
            }
        }
        return ans;
    }
};
