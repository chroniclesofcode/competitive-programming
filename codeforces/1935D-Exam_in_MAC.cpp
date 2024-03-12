#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, c;

void solve() {
    cin >> n >> c;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    // NOTE: c is actually c+1 -> we can choose 0
    // we add c+1 because we count all the dupes
    LL ans = ((c+1) * ((c+1)-1)) / 2 + (c+1);
    LL even = 0, odd = 0;
    for (LL i = 0; i < n; i++) {
        if (a[i] % 2) odd++;
        else even++;
        ans -= (a[i])/2 + 1;
        ans -= c-a[i]+1;
    }
    ans += ((even)*(even-1))/2 + even;
    ans += ((odd)*(odd-1))/2 + odd;
    cout << ans << '\n';
}

/*

*/







