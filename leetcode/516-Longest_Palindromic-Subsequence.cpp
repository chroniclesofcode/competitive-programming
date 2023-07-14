class Solution {
public:
int dp[2000][2000];
    void debug(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[i][j] = 1;
                else if (s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                ans = max(dp[i][j], ans);
            }
        }
        //debug(n);
        return ans;
    }
};
