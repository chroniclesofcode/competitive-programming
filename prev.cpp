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
const LL MX = 1e5+5;
//const LL MOD = 1e7;

LL n, w;
LL dp[101][MX];
pair<LL, LL> a[101];
/*
Knapsack:
    
*/

void solve() {
    cin >> n >> w;
    for (LL i = 1; i <= n; i++) {
        LL wi, vi;
        cin >> wi >> vi;
        a[i] = { wi, vi };
    }

    /*
        Given a bag of weight j, what is the max
        value we can hold with all items up to the ith?
        */
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= w; j++) {
            LL k = max(j-a[i].first, (LL)0);
            LL val = j-a[i].first < 0 ? 0 : a[i].second;
            dp[i][j] = max(dp[i-1][j], dp[i-1][k] + val);
        }
    }

    /*
    for (LL i = 1; i <= n; i++) {
        cout << i << ": ";
        for (LL j = 1; j <= w; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][w] << '\n';

}






