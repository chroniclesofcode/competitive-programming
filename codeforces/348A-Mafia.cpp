#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<LL,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;


void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) cin >> a[i];
    LL lo = *max_element(a.begin(), a.end());
    LL hi = (LL)1e13;
    LL ans = (LL)1e13;
    LL big = lo;
    while (lo <= hi) {
        LL mid = lo + (hi - lo)/2;
        bool flag = false;
        LL diff = 0;
        for (int i = 0; i < n; i++) {
            diff += mid - a[i];
        }
        if (diff >= mid) flag = true;
        if (flag) {
            hi = mid-1;
            ans = min(ans, mid);
        } else {
            lo = mid+1;
        }
    }
    cout << ans << '\n';
}

/*

*/



