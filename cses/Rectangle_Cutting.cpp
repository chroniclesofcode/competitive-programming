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
const LL MX = 520;
//const LL MOD = 1e7;
vector<vector<int>> dp(MX, vector<int>(MX, INT_MAX));

int a, b;

void solve() {
    cin >> a >> b;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[a][b] << endl;
}





