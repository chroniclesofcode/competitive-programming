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

LL n, x, a[MX], p[MX];
unordered_map<LL, LL> m;

/*
   1) prefix sums, find two elements which subtract to give x
*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    LL pref = 0;
    m[0] = 1;
    for (LL i = 0; i < n; i++) {
        pref = a[i] + pref;
        m[(pref%n+n)%n]++;
    }
    for (auto &e : m) {
        ans += (e.second) * (e.second-1)/2;
    }
    cout << ans << endl;

}





