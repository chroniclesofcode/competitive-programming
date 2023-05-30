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
const LL MX = 5 * 1e5;
const LL MOD = 1e9 + 7;

LL n, m;
LL a[MX];
LL dp[MX][120];

/*
   Dp[i][j] is how many different arrays up to i 
   if the ith value was j.
*/

void solve() {
    cin >> n >> m;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (LL i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (i == 0) {
                dp[i][a[i]] = 1;
            } else {
                LL t = a[i];
                dp[i][t] = dp[i-1][t] + dp[i-1][t-1] + dp[i-1][t+1];
                dp[i][t] %= MOD;
            }
            continue;
        }
        for (LL j = 1; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] =  dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= m; i++) {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}





