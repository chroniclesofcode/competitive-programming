#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 9999999;
//const LL MOD = 1e7;

LL n, x;
pair<LL, LL> dp[MX];
LL a[MX];
/*

*/

void solve() {
    cin >> n >> x;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL nums = 1 << n;
    LL sum;
    pair<LL, LL> cur;
    dp[0] = { 0, INF };
    for (LL i = 1; i < nums; i++) {
        // dp -> 0: min times, 1: curr time it's at
        pair<LL, LL> ans = { INF, INF };
        for (LL j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cur = dp[i ^ (1 << j)];
                if (cur.second + a[j] > x) {
                    (cur.first)++;
                    cur.second = a[j];
                } else {
                    cur.second += a[j];
                }
                ans = min(ans, cur);
            }
        }
        dp[i] = ans;
        //cout << i << " " << dp[i].first << " " << dp[i].second << '\n';
    }
    cout << dp[nums-1].first << endl;
}





