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

LL n, x, a[MX];

/*

*/

void solve() {
    cin >> n >> x;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    LL sum = 0;
    LL i = 0;
    LL j = 0;
    while (i < n) {
        sum += a[i];
        if (sum == x) {
            ans++;
        } else if (sum > x) {
            while (sum > x && i > j) {
                sum -= a[j];
                j++;
            }
            if (sum == x) ans++;
        }
        i++;
    }
    cout << ans << endl;
    
}





