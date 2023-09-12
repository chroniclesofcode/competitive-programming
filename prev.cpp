class Solution {
public:
    int n, m;
    bool ans = false;
    int dp[101][101][202];
    vector<vector<int>> dirs = {{1,0}, {0,1}};

    bool check(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[m-1][n-1] != ')') return false;
        if (grid[0][0] == ')') return false;
        dp[0][0][0] = 1;
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= n+m; k++) {
                    if (check(i-1, j)) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    if (check(i, j-1)) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                }
                if (grid[i][j] == ')') {
                    for (int k = 0; k <= n+m; k++) {
                        if (dp[i][j][k] > 0) {
                            dp[i][j][k] = 0;
                            if (k > 0) dp[i][j][k-1] = 1;
                        }
                    }
                } else {
                    for (int k = n+m-1; k >= 0; k--) {
                        if (dp[i][j][k] > 0) {
                            dp[i][j][k] = 0;
                            dp[i][j][k+1] = 1;
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1][0] > 0;
    }
};
// cout << "i: " << i << " j: " << j <<  " k: " << k << " dp: " << dp[i][j][k] << endl;
