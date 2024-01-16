#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

LL n, m, k, d;
LL dp[101][2][101];
void solve() {
    cin >> n >> k >> d;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) { // length
        for (int l = 0; l <= n; l++) { // tot sum
            for (int m = 1; m <= k; m++) {
                if (l >= m) {
                    if (m >= d) {
                        dp[i][1][l] += dp[i-1][0][l-m]+dp[i-1][1][l-m];
                        dp[i][1][l] %= MD;
                    } else {
                        dp[i][0][l] += dp[i-1][0][l-m];
                        dp[i][0][l] %= MD;
                        dp[i][1][l] += dp[i-1][1][l-m];
                        dp[i][1][l] %= MD;
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][1][n];
        ans %= MD;
    }
    cout << ans << '\n';
}

/*
   paths of weight n, tree has k children
   one edge must be AT LEAST d
   can be treated as a single array where you can
   choose up to k on every element.
   dp[i][j][k] = how many ways up to length i,
   with max weight j, sum up to n
*/



