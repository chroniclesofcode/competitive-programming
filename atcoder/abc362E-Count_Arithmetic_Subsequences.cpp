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
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = 998244353;

LL n;
vector<LL> a;

class Combs {
public:
    LL n, mod;
    vector<LL> fact, inv;
    Combs() = default;
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

Combs c(100, MD);

void solve() {
    cin >> n;
    a = vector<LL>(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<LL> ans(n+5);
    for (LL l = 0; l < n; l++) {
        for (LL r = l+1; r < n; r++) {
            LL diff1 = a[r]-a[l];
            if (diff1 == 0) continue;
            vector<LL> dp(n+1);
            dp[0] = 1;
            for (LL i = r+1; i < n; i++) {
                LL diff2 = a[i] - a[r];
                if (diff2 % diff1 != 0) continue;
                LL multiple = diff2 / diff1;
                if (multiple <= 0 || multiple > n) continue;
                dp[multiple] += dp[multiple-1];
                dp[multiple] %= MD;
            }
            for (LL i = 0; i < dp.size(); i++) {
                if (dp[i]) ans[i+2] += dp[i];
                ans[i+2] %= MD;
            }
        }
    }
    unordered_map<LL,LL> m;
    for (LL i = 0; i < n; i++) m[a[i]]++;
    for (auto &[k,v] : m) {
        for (LL i = 1; i <= v; i++) {
            ans[i] += c.comb(v, i);
            ans[i] %= MD;
        }
    }
    for (LL i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

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
