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
#define NINF -INF

const LL MX = 1001;
//const LL MOD = 1e7;

int n, q;
int dp[MX][MX];
int sq[MX][MX];
/*

*/

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
            int y = 0;
            if (x == '*') {
                y = 1;
            }
            sq[i][j] = y;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = sq[i][j];
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            if (i>0&&j>0) dp[i][j] -= dp[i-1][j-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        int ans = dp[y2][x2];
        if (x1 > 0) ans -= dp[y2][x1-1];
        if (y1 > 0) ans -= dp[y1-1][x2];
        if (x1 > 0 && y1 >0) ans += dp[y1-1][x1-1];
        cout << ans << '\n';
    }
}





