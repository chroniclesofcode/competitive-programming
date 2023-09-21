class Solution {
public:
    int dp[105][105];
    int minc[105][105];
    int minDistance(vector<int>& houses, int boxes) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        // for every box at house j, mincost for suffix i..n
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    minc[i][j] = 0;
                    continue;
                }
                int med = (j-i)/2;
                for (int k = i; k <= j; k++) {
                    minc[i][j] += abs(houses[i+med] - houses[k]);
                }
            }
        }
        // k boxes are left for suffix i..n
        for (int k = 1; k <= boxes; k++) {
            for (int i = 0; i < n; i++) {
                dp[k][i] = INT_MAX;
                if (k == 1) {
                    // min cost of range i to end
                    dp[k][i] = minc[i][n-1];
                } else {
                    for (int j = i; j < n; j++) {
                        dp[k][i] = min(dp[k][i], minc[i][j] + dp[k-1][j+1]);
                    }
                }
            }
        }
        return dp[boxes][0];
    }
};
