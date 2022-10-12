#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 2 * 1e6 + 100;
LL a[MX];


void solve() {
    LL n;
    cin >> n;
    LL total = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    LL ans = INF;
    for (LL i = n; i >= 1; i--) {
        if (total % i == 0) {
            LL target = total / i;
            LL tmp = 0;
            LL ret = 0;
            LL ct = 0;
            bool flag = true;
            for (LL j = 0; j < n; j++) {
                if (tmp < target) {
                    tmp += a[j];
                    ct++;
                }
                ret = max(ret, ct);
                if (tmp == target) {
                    tmp = 0;
                    ct = 0;
                } else if (tmp > target) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, ret);
            }
        }
    }
    cout << ans << '\n';
}

