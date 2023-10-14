#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n;

/*

*/

void solve() {
    cin >> n;
    LL ans = 0;
    for (LL i = 0; i <= n; i++) {
        LL tot = 0;
        LL big = 0;
        for (LL j = 1; j <= i; j++) {
            tot += j*j;
            big = max(big, j*j);
        }
        LL tmp = n;
        for (LL j = i+1; j <= n; j++) {
            tot += tmp*j;
            big = max(big, tmp*j);
            tmp--;
        }
        tot -= big;
        ans = max(ans, tot);
    }
    cout << ans << '\n';
}





