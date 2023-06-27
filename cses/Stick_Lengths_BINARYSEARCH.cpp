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
vector<LL> a;


/*

*/
LL calc(LL idx) {
    LL val = a[idx];
    LL res = 0;
    for (LL i = 0; i < n; i++) {
        res += abs(val - a[i]);
    }
    return res;
}

void solve() {
    cin >> n;
    LL b;
    for (LL i = 0; i < n; i++) {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    LL ans = INF;
    LL lo = 0;
    LL hi = n-1;
    while (lo < hi) {
        LL mid = lo + (hi-lo)/2;
        LL mid2 = mid+1;
        LL val = calc(mid);
        LL val2 = calc(mid2);
        if (val <= val2) {
            hi = mid;
        } else {
            lo = mid2;
        }
        ans = min({ans, val, val2});
    }
    if (ans == INF) ans = 0;
    cout << ans << endl;
}





