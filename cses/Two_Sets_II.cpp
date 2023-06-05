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
const LL MX = 510;
const LL MOD = 1e9 + 7;

LL n;
LL dp[MX][63000];

/*
   Very interesting problem
    0-1 knapsack, lot of small nuances to take care of.
    At first, DP was wrong becasue I didn't consider my max sum.
    Then, I did a real knapsack, when what I should be doing
    is considering the different ways to make things... Which is
    actually an EASIER recursion than a max.
*/

void solve() {
    cin >> n;
    LL sum = n * (n+1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    dp[0][0] = 1;
    for (LL i = 1; i < n; i++) {
        for (LL j = 0; j <= sum; j++) {
            if (j - i >= 0) {
                // This line adds the number of ways to make
                // if you include it, and the number of ways
                // if you didn't include it.
                // The only deciding factor is whether j-i
                // is greater than 0. Because that's recursion
                // for you. You don't even need to consider
                // whether it is possible, it is definitely
                // possible IF dp[i-1][j-i] > 0
                // Also had nasty bug where I did dp[i][j-i]
                // instead of dp[i-1][j-i], because we shouldn't
                // include i if we've already included it!
                dp[i][j] = dp[i-1][j-i] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n-1][sum] << '\n';
}





