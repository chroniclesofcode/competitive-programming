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

LL n, t;
vector<LL> k;
/*

*/

void solve() {
    cin >> n >> t;
    LL x;
    LL smol = INF;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        k.push_back(x);
        smol = min(smol, x);
    }
    LL lo = 1;
    LL hi = t * smol;
    LL mid;
    LL ans = INF;
    while (lo <= hi) {
        mid = lo + (hi - lo)/2;
        LL tot = 0;
        for (LL i = 0; i < n; i++) {
            tot += mid/k[i];
        }
        if (tot >= t) {
            hi = mid-1;
            ans = min(ans, mid);
        } else {
            lo = mid+1;
        }
    }
    cout << ans << endl;
}

