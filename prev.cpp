class Solution {
public:
    static constexpr int mx = (int)1e4 + 5;
    double dp[mx];
    double new21Game(int n, int k, int maxPts) {
        dp[0] = 1.0;
        dp[1] = -1.0;
        double run = 0;
        for (int i = 0; i < k; i++) {
            run += dp[i];
            if (i+1 <= n) dp[i+1] += run / maxPts;
            if (i+maxPts+1 <= n) dp[i+maxPts+1] -= run / maxPts;
        }
        double ans = 0;
        for (int i = k; i <= n; i++) {
            run += dp[i];
            ans += run;
        }
        return ans;
    }
};
