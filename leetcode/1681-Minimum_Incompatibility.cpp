class Solution {
public:
    int nct[17], vis[17];
    int dp[17][65537], cost[65537];
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return 0;
        int inf = (int)1e9 + 33;
        int sz = n/k;
        int LG = 1 << n;
        for (int i = 0; i < n; i++) {
            nct[nums[i]]++;
            if (nct[nums[i]] > k) return -1;
            for (int j = 0; j < LG; j++) {
                dp[i][j] = inf;
            }
        }
        for (int i = 1; i < LG; i++) {
            memset(vis, 0, sizeof(vis));
            int big = 0, small = inf;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    if (vis[nums[j]]) {
                        cost[i] = inf;
                        break;
                    }
                    big = max(big, nums[j]);
                    small = min(small, nums[j]);
                    vis[nums[j]] = 1;
                }
            }
            if (cost[i] < inf) cost[i] = big - small;
        }
        for (int i = 0; i < k; i++) {
            // pretend j is visited already, what is
            // dp of i when taking the leftovers?
            for (int j = 0; j < LG; j++) {
                if (i == 0) {
                    if (__builtin_popcount(j) == sz) {
                        dp[i][j] = cost[j];
                    }
                    continue;
                }
                int unset = j^(LG-1);
                for (int l = unset; l > 0; l = (l-1)&unset) {
                    if (__builtin_popcount(l) != sz) continue;
                    dp[i][j|l] = min(dp[i][j|l], dp[i-1][j] + cost[l]);
                }
            }
        }
        return dp[k-1][LG-1];
    }
};
/*
    You want to distribute the array such that the max-min
    is the smallest. Everything is close together.
    iterate through all 0..n/k buckets using a bitset DP
    we're saying up to this bucket, if all of this is
    already used, what is the min cost?
*/
