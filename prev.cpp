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

const LL MX = 1e8;
//const LL MOD = 1e7;

LL n1, n2, k1, k2;
// Num of ways to arrange with these limitations
LL dp[101][101][11][11];

/*

*/

void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= k1; k++) {
                for (int l = 0; l <= k2; l++) {
                    int ans = 0;
                    if (i + j == 0) {
                        ans = 1;
                    } else {
                        if (i > 0 && k > 0) {
                            ans += dp[i-1][j][k-1][k2];
                        }
                        if (j > 0 && l > 0) {
                            ans += dp[i][j-1][k1][l-1];
                        }
                        ans %= MX;
                    }
                    dp[i][j][k][l] = ans;
                }
            }
        }
    }
    cout << dp[n1][n2][k1][k2] << '\n';
}





