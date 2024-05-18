class Solution {
public:
    int dp[31][31][31];
    int pref[31];
    int pfs(int i, int j) {
        return i == 0 ? pref[j] : pref[j]-pref[i-1];
    }
    int mergeStones(vector<int>& stones, int piles) {
        int n = stones.size();
        int run = 0;
        int inf = (int)1e8 + 10;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k <= piles; k++) 
                    dp[i][j][k] = inf;
        for (int i = 0; i < n; i++) {
            dp[i][i][1] = 0;
            run += stones[i];
            pref[i] = run;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                for (int k = min(j-i+1,piles); k >= 1; k--) {
                    if (k == 1) {
                        if (i == j) continue;
                        dp[i][j][1] = dp[i][j][piles] + pfs(i, j);
                        continue;
                    }
                    int tmp = inf;
                    for (int l = i; l < j; l++) {
                        tmp = min(tmp, dp[i][l][1] + dp[l+1][j][k-1]);
                    }
                    dp[i][j][k] = tmp;
                }
            }
        }
        return dp[0][n-1][1] >= inf ? -1 : dp[0][n-1][1];
    }
};
/*
    dp[i][j][k] -> range DP. How to merge i->j into
    k different piles. 
*/