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

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1e4 + 1;
constexpr LL MD = 998244353;

LL n, m;

LL dp[MX][(1 << 10)+1];
void solve() {
    cin >> m >> n;
    LL LG = (1 << m);
    vector<LL> a(m);
    for (LL i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<LL> f(m);
    for (LL i = 0; i < m; i++) {
        // we are saying a[i] is
        // mapped to by f[a[i]] indices
        f[a[i]] |= (1 << i);
    }
    for (LL i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i][LG-1] = 1;
            continue;
        }
        for (LL j = 0; j < LG; j++) {
            for (LL k = 0; k < m; k++) {
                if (j & (1 << k)) {
                    LL mask = (j^(1<<k)) | f[k];
                    dp[i][mask] += dp[i-1][j];
                    dp[i][mask] %= MD;
                }
            }
        }
    }

    LL ans = 0;
    for (LL j = 0; j < LG; j++) {
        ans += dp[n][j];
        ans %= MD;
    }
    cout << ans << '\n';
}

/*
f[2] = 1,3
f[1] = 2
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
