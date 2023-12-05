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
const LL MX = 2 + (LL)1e5+1;
//const LL MOD = 1e7;

LL n;
LL suf[MX];
/*
   for each number, we either take extend off the previous
   or we don't. Take the max at every step.
   0 = just split, 1 = take max of prevs
*/

void solve() {
    cin >> n;
    vector<LL> a;
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        a.push_back(x);
    }
    LL p = 0;

    for (LL i = n-1; i >= 0; i--) {
        p += a[i];
        suf[i] = p;
    }
    LL ans = a[0], k = 1;
    for (LL i = 1; i < n; i++) {
        if (suf[i] >= 0) {
            ans += a[i] * (++k);
        } else {
            ans += a[i] * k;
        }
    }
    cout << ans << '\n';
}





