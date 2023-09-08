class Solution {
public:
    int dp[1001][1001];
    int pref[501];
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        int p = 0;
        for (int i = 0; i < n; i++) {
            p += stones[i];
            pref[i] = p;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++)  { 
                if (i == j) {
                    continue;
                }
                int tot = i > 0 ? pref[j]-pref[i-1] : pref[j];
                int sm = 0;
                for (int k = i; k <= j; k++) {
                    sm += stones[k];
                    if (sm > tot-sm) {
                        dp[i][j] = max(dp[i][j], tot-sm+dp[k+1][j]);
                    } else if (tot-sm > sm) {
                        dp[i][j] = max(dp[i][j], sm+dp[i][k]);
                    } else {
                        dp[i][j] = max(dp[i][j], sm+max(dp[i][k],dp[k+1][j]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
