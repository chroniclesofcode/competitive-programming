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
const LL MX = 5 * 1e3;
//const LL MOD = 1e7;
array<LL, 2> dp[MX][MX];
LL a[MX];
LL n;

/*
   dp[i][j][0..1] = max score of first player if
   the game is played from LLerval i to j.
   0 is max score he can achieve if he goes first
   1 is max score he can achieve if he goes second
*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (LL i = n-1; i >= 0; i--) {
        for (LL j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = { a[i], 0 }; 
            } else {
                LL lp = a[i]+dp[i+1][j][1];
                LL rp =  a[j]+dp[i][j-1][1];
                if (lp > rp) {
                    dp[i][j] = { lp, dp[i+1][j][0] };
                } else {
                    dp[i][j] = { rp, dp[i][j-1][0] };
                }
            }
        }
    }
    cout << dp[0][n-1][0] << '\n';
}





