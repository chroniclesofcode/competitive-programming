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
    cin >> n >> x;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    p[0] = a[0];
    for (LL i = 1; i < n; i++) {
        p[i] = a[i] + p[i-1];
    }
    for (LL i = 0; i < n; i++) {
        ans += m[p[i]-x];
        m[p[i]]++;
    }
    cout << ans + m[x] << endl;

}





