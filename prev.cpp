#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr LL MX = 3 * 1e5;
constexpr int MD = 998244353;
int n, m, k;

int dp[MX], lodd[MX], rodd[MX], leven[MX], reven[MX];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        e += a[i] % 2 == 0 ? 1 : 0;
        o += a[i] % 2 == 1 ? 1 : 0;
        lodd[i] = o; leven[i] = e;
    }
    o = 0, e = 0;
    for (int i = n-1; i >= 0; i--) {
        e += a[i] % 2 == 0 ? 1 : 0;
        o += a[i] % 2 == 1 ? 1 : 0;
        rodd[i] = o; reven[i] = e;
    }
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i] % 2 == 0) {
            ans += lodd[i-1] * rodd[i+1];
            ans += leven[i-1] * reven[i+1];
        } else {
            ans += lodd[i-1] * reven[i+1];
            ans += leven[i-1] * rodd[i+1];
        }
    }
    cout << ans << '\n';
}

/*

*/



