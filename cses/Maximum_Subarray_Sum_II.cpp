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

LL n, x, y, a[MX], p[MX];
multiset<LL> s;
/*

*/

void debug() {
    cout << "set: ";
    for (auto &e : s) {
        cout << e << ' ';
    }
    cout << endl;
}

void solve() {
    cin >> n >> x >> y;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (LL i = 1; i <= n; i++) {
        p[i] = a[i] + p[i-1];
    }
    LL ans = NINF;
    for (LL i = x; i <= y; i++) {
        ans = max(ans, p[i]);
    }
    for (LL i = 1; i <= n-x; i++) {
        if (i > y-x+1) {
            s.erase(s.find(p[i-(y-x+1)]));
        }
        s.insert(p[i]);
        ans = max(ans, p[i+x]-*s.begin());
    }
    cout << ans << endl;
}





