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
const LL MX = 2 * 1e5 + 20;
LL x[MX];
LL pref[MX];
LL maxes[MX];


void solve() {
    LL n, q;
    cin >> n >> q;
    for (LL i = 0; i < n; i++) {
        cin >> x[i];
    }
    pref[0] = x[0];
    maxes[0] = x[0];
    for (LL i = 1; i < n; i++) {
        pref[i] = pref[i-1] + x[i];
        maxes[i] = max(maxes[i-1], x[i]);
    }
    LL l;
    for (LL i = 0; i < q; i++) {
        cin >> l;
        auto v = upper_bound(maxes, maxes+n, l);
        LL idx = v - maxes;
        //cout << "VALUE " << *v << " IDX: " << idx << endl;
        if (v == maxes+n) {
            cout << pref[n-1] << " ";
        } else {
            cout << pref[idx-1] << " ";
        }
    }
    cout << '\n';

}

