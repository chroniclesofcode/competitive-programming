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
constexpr LL MX = 2 * 1e5 + 101;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

LL dp[MX][6][2];

void solve() {
    string s;
    cin >> s;
    LL n = s.size();
    reverse(s.begin(), s.end());
    vector<LL> a(n);
    vector<LL> convert = { 0, 1, 10, 100, 1000, 10000 };
    for (LL i = 0; i < n; i++) {
        if (s[i] == 'A') a[i] = 1;
        else if (s[i] == 'B') a[i] = 2;
        else if (s[i] == 'C') a[i] = 3;
        else if (s[i] == 'D') a[i] = 4;
        else if (s[i] == 'E') a[i] = 5;
        for (LL j = 1; j <= 5; j++) {
            dp[i][j][0] = -LINF;
            dp[i][j][1] = -LINF;
        }
    }
    vector<LL> pref(6, 0);
    dp[0][a[0]][0] = convert[a[0]];
    for (LL i = 1; i <= 5; i++) {
        dp[0][i][1] = convert[i];
    }
    for (LL i = 1; i < n; i++) {
        // max reached is j
        for (LL j = 1; j <= 5; j++) {
            LL lim = max(j, a[i]);
            // keeping it the same
            if (a[i] >= j) {
                dp[i][lim][0] = max(dp[i][lim][0], dp[i-1][j][0] + convert[a[i]]);
                dp[i][lim][1] = max(dp[i][lim][1], dp[i-1][j][1] + convert[a[i]]);
            } else {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] - convert[a[i]]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] - convert[a[i]]);
            }
            // changed num to k
            for (LL k = 1; k <= 5; k++) {
                if (k < j) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] - convert[k]);
                } else if (k >= j) {
                    dp[i][k][1] = max(dp[i][k][1], dp[i-1][j][0] + convert[k]);
                }
            }
        }
    }
    LL ans = -LINF;
    for (LL i = 1; i <= 5; i++) {
        ans = max(ans, dp[n-1][i][0]);
        ans = max(ans, dp[n-1][i][1]);
    }
    cout << ans << '\n';
}

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
