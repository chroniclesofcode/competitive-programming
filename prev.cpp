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

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n;
unordered_map<LL, LL> m;
/*

*/

void solve() {
    // TLE if not reserving/increasing load factor
    m.reserve(1024);
    m.max_load_factor(0.25);
    cin >> n;
    LL a;
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a;
        if (m[a] == 0) {
            ans++;
        }
        m[a]++;
    }
    cout << ans << endl;
}





