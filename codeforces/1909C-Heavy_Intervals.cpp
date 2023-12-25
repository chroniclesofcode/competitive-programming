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
    vector<LL> l(n), r(n), c(n);
    for (LL i = 0; i < n; i++) cin >> l[i];
    for (LL i = 0; i < n; i++) cin >> r[i];
    for (LL i = 0; i < n; i++) cin >> c[i];
    multiset<LL> ls;
    for (auto len : l) ls.insert(len);
    sort(r.begin(), r.end());
    sort(c.begin(), c.end(), greater<LL>());
    vector<int> diffs;
    for (int i = 0; i < r.size(); i++) {
        auto it = ls.lower_bound(r[i]);
        it--;
        diffs.push_back(r[i]-*it);
        ls.erase(it);
    }
    sort(diffs.begin(), diffs.end());
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += diffs[i] * c[i];
    }
    cout << ans << '\n';
}

/*

*/







