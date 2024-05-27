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

LL dp[51][100001];

void solve() {
    LL salary;
    cin >> m >> salary;
    vector<arr2> a;
    LL hsz = 0;
    for (LL i = 0; i < m; i++) {
        LL c, h; cin >> c >> h;
        a.push_back({c, h});
        hsz += h;
    }
    for (LL i = 0; i < m; i++) {
        auto &[c, h] = a[i];
        dp[i][0] = 0;
        if (i == 0) {
            for (LL j = 1; j <= hsz; j++) dp[i][j] = LINF;
            if (c == 0) {
                dp[i][h] = 0;
            }
            continue;
        }
        LL accrued = i * salary;
        for (LL j = 1; j <= hsz; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - h >= 0 && dp[i-1][j-h]+c <= accrued) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-h]+c);
            }
        }
    }
    LL ans = 0;
    for (LL j = 0; j <= hsz; j++) {
        if (dp[m-1][j] < LINF) {
            ans = max(ans, j);
        }
    }
    cout << ans << '\n';

}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
