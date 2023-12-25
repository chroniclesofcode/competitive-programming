#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

LL n, m, k;

void solve() {
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool same = true;
    LL small = a[0];
    for (int i = 1; i < n; i++) {
        small = min(small, a[i]);
        if (a[i] != a[i-1]) { same = false; break; }
    }
    if (same) {
        cout << "0\n";
        return;
    }
    LL res = a[0] - k;
    int allpos = 1, allneg = 1, allzero = 1;
    for (int i = 0; i < n; i++) {
        a[i] -= k;
        res = gcd(res, a[i]);
        if (a[i] > 0) {
            allneg = 0; allzero = 0;
        } else if (a[i] == 0) {
            allpos = 0; allneg = 0;
        } else if (a[i] < 0) {
            allpos = 0; allzero = 0;
        }
    }
    if (!allpos && !allneg && !allzero) {
        cout << "-1\n";
        return;
    } else if (allzero) {
        cout << "0\n";
        return;
    }
    if (allneg) {
        res = -res;
    }
    LL ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (a[i] / res) - 1;
    }
    cout << ans << '\n';

}

/*
*/







