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
const LL MX = 2 * 1e5 + 20;
//const LL MOD = 1e7;

LL n;
array<LL, 3> a[MX];
LL dp[MX];
/*
   dp[i] = max profit that can be gained if we end on this day
*/

void solve() {
    cin >> n;
    map<LL, LL> comp;
    for (LL i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1]++;
        comp[a[i][0]];
        comp[a[i][1]];
    }
    LL ct = 0;
    for (auto &e : comp) {
        e.second = ct++;
    }
    vector<vector<pair<LL, LL>>> p(ct);
    for (LL i = 0; i < n; i++) {
        p[comp[a[i][1]]].push_back({comp[a[i][0]], a[i][2]});
    }
    for (LL i = 0; i < ct; i++) {
        if (i > 0) dp[i] = dp[i-1];

        for (auto &v : p[i]) {
            dp[i] = max(dp[i], dp[v.first] + v.second);
        }
    }
    cout << dp[ct-1] << '\n';

}



