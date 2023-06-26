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
LL a[MX];
/*

*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL curr = a[0];
    LL ans = curr;
    LL pos = a[0] > 0 ? a[0] : 0;
    LL neg = a[0] > 0 ? 0 : -a[0]; // Sum of negatives after recent positive
    for (LL i = 1; i < n; i++) {
        curr += a[i];
        ans = max(ans, curr);
        if (a[i] > 0) {
            if (a[i-1] <= 0 && neg > pos) {
                curr = a[i];
                pos = a[i];
                neg = 0;
            } else {
                pos += a[i];
            }
        } else {
            if (neg > pos) {
                curr = a[i];
                pos = 0;
                neg = -a[i];
            } else {
                neg += -a[i];
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}





