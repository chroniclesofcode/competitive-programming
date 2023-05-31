#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
const LL MOD = 1e9 + 7;

LL n;
LL dp[MX][2];

void solve();
void preprocess();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    preprocess();
    LL t;
    cin >> t;
    while (t--)
        solve();
}

void preprocess() {
    // 0 is when top row is connected
    // 1 is when top row isnt connected
    // dp finds transitions from prev top row to curr top row
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (LL i = 2; i <= 1e6 + 1; i++) {
        dp[i][0] += 2 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] += dp[i-1][0] + 4 * dp[i-1][1];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
}

void solve() {
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}





