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
    LL t;
    cin >> t;
    while (t--)
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
    LL odd = 0, even = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) odd = 1;
        else even = 1;
    }
    if (odd && even) {
        cout << "2\n";
        return;
    }
    LL val = 2;
    for (LL i = 0; i <= 60; i++) {
        unordered_set<LL> s;
        for (LL j = 0; j < a.size(); j++) {
            s.insert(a[j] % val);
            if (s.size() > 2) break;
        }
        if (s.size() == 2) {
            cout << val << '\n';
            return;
        }
        val *= 2;
    }
    cout << -1 << '\n';
}

/*

*/







