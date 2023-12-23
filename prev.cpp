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
    if (n == 1) {
        cin >> m;
        cout << m << '\n';
        return;
    }
    vector<LL> a;
    LL lead = 0;
    LL big = NINF;
    for (LL i = 0; i < n; i++) {
        cin >> m;
        big = max(big, m);
        a.push_back(m);
        if (m > 0)
            lead = 1;
    }
    if (lead == 0) {
        cout << big << '\n';
        return;
    }
    n = a.size();
    LL s1 = 0, s2 = 0;
    for (LL i = 0; i < n; i++) {
        if ((i & 1) && a[i] > 0) {
            s1 += a[i];
        }
    }
    for (LL i = 0; i < n; i++) {
        if (!(i & 1) && a[i] > 0) {
            s2 += a[i];
        }
    }
    cout << max(s1, s2) << '\n';
}

/*

*/







