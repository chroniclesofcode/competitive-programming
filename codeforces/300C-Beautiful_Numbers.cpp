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

        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = (int)1e6 + 10;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, a, b;

LL factorial[MX];

long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1LL % mod;
    if (deg & 1LL) return binpow(val, deg - 1LL, mod) * val % mod;
    long long res = binpow(val ,deg >> 1LL, mod);
    return (res*res) % mod;
}

LL C(LL _n, LL _k) {
    return (factorial[_n] * binpow((factorial[_k] * factorial[_n - _k])%MD, MD-2, MD)) % MD;
}

void solve() {
    cin >> a >> b >> n;

    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MD;
    }
    LL first = 0, second = 0;
    LL ans = 0;
    for (LL i = 0; i <= n; i++) {
        first = i;
        second = n - i;
        LL num = a * first + b * second;
        bool flag = true;
        while (num > 0) {
            LL tmp = num % 10;
            if (tmp != a && tmp != b) {
                flag = false;
                break;
            }
            num /= 10;
        }
        if (flag) {
            ans += C(n, i);
            ans %= MD;
        }
    }
    cout << ans << '\n';
}

/*

*/



