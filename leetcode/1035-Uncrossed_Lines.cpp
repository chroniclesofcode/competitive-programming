class Solution {
public:
    int dp[600][600];
    void debug(vector<int>& n1, vector<int>& n2) {
        for (int i = 0; i < n1.size(); i++) {
            for (int j = 0; j < n2.size(); j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
    }
    int maxUncrossedLines(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        int m = n2.size();
        int ans = 0;
        // nums1
        for (int i = 0; i < n; i++) {
            // nums2
            for (int j = 0; j < m; j++) {
                if (n1[i] == n2[j]) {
                    dp[i][j] = 1;
                    if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                    if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
                } else {
                    if (j > 0) dp[i][j] = dp[i][j-1];
                    if (i > 0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
                    if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                }
                ans =  max(ans, dp[i][j]);
            }
        }
        //debug(n1, n2);
        return ans;
    }
};
