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
constexpr LL MX = 2 * 1e3;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<LL>());
    LL p = 0;
    vector<LL> pref(n);
    for (LL i = 0; i < n; i++) {
        p += a[i];
        pref[i] = p;
    }
    LL ans = 0;
    for (LL k = 1; k <= n; k *= 4) {
        ans += pref[k-1];
    }
    cout << ans << '\n';
    
}

/*
*/



