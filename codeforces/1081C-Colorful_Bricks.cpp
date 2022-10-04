#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}


const LL MXSZ = 2100;
const LL MOD = 998244353;
LL dp[MXSZ][MXSZ];

void Debug(LL n, LL k) {
    for (LL i = 1; i <= n; i++) {
        for (LL j = 0; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    // number of bricks, colors, bricks diff to the left
    LL n, m, k;
    cin >> n >> m >> k;
    /*
       dp[i][j] = different number of ways to colour i bricks
       using j bricks that are different to the one on the left

       if i=1, dp[i][j] = m, only one brick, can't really do anything
       if j=0, all bricks are the same, dp[i][j] = m

       for all bricks with j-1, we add a different brick onto the end
       for all bricks with j, we add the same brick to it

       2 bricks, k = 1
       1 brick k = 0 -> different
       1 brick k = 1 -> same
    */

    for (LL i = 1; i <= n; i++) {
        for (LL j = 0; j <= k; j++) {
            if (j > 0 && i == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1) {
                dp[i][j] = m;
                continue;
            }
            if (j == 0) {
                dp[i][j] = m;
                continue;
            }
            dp[i][j] = dp[i-1][j-1] * (m - 1) + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    //Debug(n, k);
    cout << dp[n][k] << '\n';
}

