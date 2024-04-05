#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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

LL n, m, k;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL lo = -LLONG_MAX / 2;
    for (LL i = 0; i < n-1; i++) {
        LL delta = lo - a[i];
        a[i] += delta;
        a[i+1] += delta;
    }
    if (a[n-1] >= a[n-2]) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

/*

*/







