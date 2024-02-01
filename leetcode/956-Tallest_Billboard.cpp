class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int tot = accumulate(rods.begin(), rods.end(), 0);
        auto dp = vector<vector<int>>(n+1, vector<int>(tot*2+1, INT_MIN));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][tot+rods[i]] = rods[i];
                dp[i][tot-rods[i]] = 0;
                dp[i][tot] = 0;
                continue;
            }
            for (int j = 0; j <= tot*2; j++) {
                // ignore the rod
                dp[i][j] = max(dp[i][j], dp[i-1][j]);

                // use ith rod in left
                if (rods[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-rods[i]] + rods[i]);
                }

                // ith rod goes in other group
                if (j + rods[i] <= tot*2) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j+rods[i]]);
                }
            }
        }
        return dp[n-1][tot];
    }
};
/*
    dp[i][j] = 0..i rods, if the difference left - right = j, where 
    left is always larger than right - what is the highest height?
*/

