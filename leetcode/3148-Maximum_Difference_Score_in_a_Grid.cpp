class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int v = grid[i][j];
                dp[i][j] = v;
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
                if (i > 0) ans = max(ans, v-dp[i-1][j]);
                if (j > 0) ans = max(ans, v-dp[i][j-1]);
            }
        }
        return ans;
    }
};
