#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = 998244353;
int n, m, k;

class Combs {
public:
    LL n, mod;
    vector<LL> fact, inv;
    Combs(LL sz, LL md) : n(sz), mod(md), fact(sz+1), inv(sz+1) {
        fact[0] = 1;
        for (LL i = 1; i <= sz; i++) {
            fact[i] = (i * fact[i-1]) % md;
        }
        inv[0] = 1;
        inv[sz] = modpow(fact[n], md-2);
        for (LL i = sz - 1; i >= 0; i--) {
            inv[i] = (inv[i+1] * (i+1)) % md;
        }
    }

    LL modpow(LL b, LL e) {
        LL ans = 1;
        while(e) {
            if(e & 1)
                ans = (ans * b) % mod;
            b = (b * b) % mod;
            e >>= 1;
        }
        return ans;
    }

    LL comb(LL a, LL b) {
        if (a < 0 || b < 0 || b > a) return 0;
        return (fact[a] * inv[b] % mod) * inv[a-b] % mod;
    }
};

Combs b(1001, MD);
int dp[26][1001];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= a[0]; i++) {
        dp[0][i] = 1;
    }

    for (int c = 1; c < 26; c++) {
        for (int i = 0; i <= n; i++) {
            dp[c][i] = dp[c-1][i];
            for (int j = 1; j <= a[c]; j++) {
                if (i - j >= 0) {
                    dp[c][i] += (dp[c-1][i-j] * b.comb(i, j)) % MD;
                    dp[c][i] %= MD;
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[25][i];
        ans %= MD;
    }
    cout << ans << '\n';
}

/*
   dp[i][j] = num ways using only chars 0..i, arrange in
   length j.
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
