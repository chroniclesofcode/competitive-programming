class Solution {
public:
    const int INF = 1e9;
    int dp[102][102][102];
    int removeBoxes(vector<int>& boxes) {
        const int n = boxes.size();
        if (n == 0) return 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][i][j] = (j+1)*(j+1);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                for (int k = 0; k <= i; k++) {
                    int ans = (k+1)*(k+1) + dp[i+1][j][0];
                    for (int l = i+1; l <= j; l++) {
                        if (boxes[i] == boxes[l]) {
                            ans = max(ans, dp[i+1][l-1][0] + dp[l][j][k+1]);
                        }
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][n-1][0];
    }
};
