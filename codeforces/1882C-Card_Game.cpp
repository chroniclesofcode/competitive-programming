#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, dp[MX][2], a[MX];

/*
*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (LL i = n-1; i >= 0; i--) {
        if (i == n-1) {
            dp[i][0] = 0;
            dp[i][1] = max((LL)0,a[i]);
        } else {
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = max({dp[i+1][0], a[i] + dp[i+1][1], dp[i+1][0] + a[i]});
        }
    }
    cout << dp[0][1] << '\n';
}





