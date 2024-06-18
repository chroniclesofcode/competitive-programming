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
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 2 * 1e5;
constexpr int MD = (int)1e9 + 7;

LL n, q;

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

void solve() {
    Combs c(1000, 1e9 + 7);
    cout << c.comb(32, 3) << '\n';
    cout << c.comb(7, 2) << '\n';
    cout << c.comb(4, 1) << '\n';
    cout << c.comb(3, 0) << '\n';
    cout << c.comb(12, 6) << '\n';
}

