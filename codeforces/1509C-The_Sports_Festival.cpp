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

const LL MX = 2010;
//const LL MOD = 1e7;

LL n, dp[MX][MX];
vector<LL> a;
/*

*/

void debug() {
    cout << "\n start debug \n";
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if (dp[i][j] != INF)
                cout << dp[i][j] << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void solve() {
    cin >> n;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for (LL i = n-1; i >= 0; i--) {
        for (LL j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            if (i < n) {
                dp[i][j] = min(dp[i][j], dp[i+1][j] + a[j] - a[i]);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + a[j] - a[i]);
            }
        }
    }
    //debug();
    cout << dp[0][n-1] << '\n';
}





