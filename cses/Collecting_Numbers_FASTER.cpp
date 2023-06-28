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

LL n, a[MX], pos[MX];

/*

*/

void solve() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    LL ans = 1;

    for (LL i = 1; i <= n; i++) {
        if (a[i] < n && pos[a[i]+1] < i) {
            ans++;
        }
    }
    cout << ans << endl;
}





