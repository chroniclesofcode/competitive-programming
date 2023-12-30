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
constexpr int MD = (int)1e8;

int n1, n2, k1, k2;
int dp[101][101][2];
void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= k1; i++) {
        dp[i][0][0] = 1;
    }
    for (int i = 0; i <= k2; i++) {
        dp[0][i][1] = 1;
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            // 0 is footmen, 1 is horsemen
            for (int k = 1; k <= min(i, k1); k++) {
                dp[i][j][0] += dp[i-k][j][1];
                dp[i][j][0] %= MD;
            }
            for (int k = 1; k <= min(j, k2); k++) {
                dp[i][j][1] += dp[i][j-k][0];
                dp[i][j][1] %= MD;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1])%MD << '\n';
}

/*

*/



