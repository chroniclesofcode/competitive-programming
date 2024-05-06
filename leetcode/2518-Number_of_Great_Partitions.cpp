class Solution {
public:
    int dp[1001][1001];
    int n, t;
    void debug() {
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= t; k++) {
                cout << dp[i][k] << ' ';
            }
            cout << '\n';
        }
    }
    int countPartitions(vector<int>& nums, int target) {
        using ll = long long;
        int md = (int)1e9 + 7;
        sort(nums.begin(), nums.end());
        n = nums.size(); t = target;

        ll sm = 0, tot = 1;
        for (int i = 0; i < n; i++) tot = (tot * 2) % md;
        tot -= 2;

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            sm += nums[i];
        }
        if (sm / 2 < target) return 0;
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= t; k++) {
                if (i == 0) {
                    dp[i][k] = (nums[i] == k); continue;
                }
                dp[i][k] = dp[i-1][k];
                if (k >= nums[i]) {
                    dp[i][k] += dp[i-1][k-nums[i]];
                    dp[i][k] %= md;
                }
            }
        }
        ll ans = tot;
        for (int k = 1; k <= t; k++) {
            if (k == t && sm/2 >= k) continue;
            ans -= 2*dp[n-1][k];
        }
        return (((ans%md) + md) % md);
    }
};
