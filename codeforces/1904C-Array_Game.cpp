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

LL n, k;

/*

*/

void solve() {
    cin >> n >> k;
    vector<LL> a;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        a.push_back(x);
    }
    if (k >= 3) {
        cout << 0 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    LL ans = a[0];
    if (k == 1) {
        for (int i = 1; i < n; i++) {
            ans = min(ans, a[i] - a[i-1]);
        }
        cout << ans << '\n';
    } else if (k == 2) {
        vector<LL> diffs((n*(n-1))/2 + 5);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                LL v = abs(a[j]-a[i]);
                diffs.push_back(v);
                ans = min(ans, v);
            }
        }
        sort(diffs.begin(), diffs.end());
        for (int i = 0; i < n; i++) {
            LL v = a[i];
            auto it = lower_bound(diffs.begin(), diffs.end(), v);
            if (it != diffs.end()) {
                ans = min(ans, *it-v);
            }
            if (it != diffs.begin()) {
                it--;
                ans = min(ans, v-*it);
            }
        }
        cout << ans << '\n';
    }
}





