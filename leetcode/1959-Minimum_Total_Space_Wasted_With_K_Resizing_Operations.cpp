class Solution {
public:
    int cost[201][201];
    int dp[201][201];
    int minSpaceWastedKResizing(vector<int>& nums, int rsz) {
        int n = nums.size();
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) continue;
                int b = nums[i];
                for (int k = i; k <= j; k++) {
                    b = max(b, nums[k]);
                }
                int tot = 0;
                for (int k = i; k <= j; k++) {
                    tot += b - nums[k];
                }
                cost[i][j] = tot;
            }
        }
        for (int k = 0; k <= rsz; k++) {
            for (int i = 0; i < n; i++) {
                dp[k][i] = k == 0 ? cost[0][i] : dp[k-1][i];
                if (k == 0) continue;
                for (int j = 0; j <= i; j++) {
                    dp[k][i] = min(dp[k][i], dp[k-1][j]+cost[j+1][i]);
                }
            }
        }
        return dp[rsz][n-1];
    }
};
/*
    range dp -> for a range, what is min wasted space for a num?
    dp[k][i] using k resizes for segment 0..i
*/
