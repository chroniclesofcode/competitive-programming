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

LL n, a[MX];

/*

*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = a[0];
    LL res = a[0];
    for (LL i = 1; i < n; i++) {
        ans = max(ans + a[i], a[i]);
        res = max(res, ans);
    }
    cout << res << endl;
}





