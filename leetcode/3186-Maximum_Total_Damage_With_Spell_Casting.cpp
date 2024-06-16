class Solution {
public:
    long long maximumTotalDamage(vector<int>& p) {
        using ll = long long;
        sort(p.begin(), p.end());
        vector<array<ll,2>> a;
        int run = 0;
        int sz = p.size();
        for (int i = 0; i < sz; i++) {
            if (i == sz-1) {
                a.push_back({p[i], run+1});
                continue;
            }
            if (p[i] == p[i+1]) {
                run++;
            } else {
                a.push_back({p[i], run+1});
                run = 0;
            }
        }
        int n = a.size();
        vector<ll> dp(n+1, 0);
        for (int i = 0; i < n; i++) {
            int j = i-1;
            while (j >= 0 && a[j][0] >= a[i][0]-2) {
                j--;
            }
            dp[i] = i > 0 ? max(dp[i-1], a[i][0]*a[i][1]) : a[i][0] * a[i][1];
            if (j >= 0) {
                dp[i] = max(dp[i], dp[j] + a[i][0] * a[i][1]);
            }
        }
        return dp[n-1];
    }
};
/*
dp[i] = a[i][0] * a[i][1] + dp[j where j is just under a[i][0]-2]
*/
