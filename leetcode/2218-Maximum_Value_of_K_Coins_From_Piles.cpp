class Solution {
public:
    int dp[1001][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // 0..i piles, 0..j coins used total
        int n = piles.size();
        vector<vector<int>> prefix = piles;
        for (auto &e: prefix) {
            int pref = 0;
            for (int i = 0; i < e.size(); i++) {
                pref += e[i];
                e[i] = pref;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int m = piles[i].size();
                if (j < m) dp[i][j] = prefix[i][j]; // base: only choose this
                if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]); // don't choose this
                // choose some of comb of 0..j coins
                for (int l = 0; l <= min(j,m-1); l++) {
                    if (i>0 && j-1-l>=0)dp[i][j] = max(dp[i][j], dp[i-1][j-1-l] + prefix[i][l]);
                }
            }
        }
        return dp[n-1][k-1];
    }
};
