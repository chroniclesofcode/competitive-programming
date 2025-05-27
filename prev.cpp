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
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;


void solve() {
    cin >> n;
    string s;
    cin >> s;
    LL r = 0;
    for (LL i = 0; i < n; i++) {
        if (s[i] == '1') r++;
    }
    LL l = 0;
    LL ans = 0; 
    for (LL i = 0; i < n; i++) {
        if (s[i] == '1') {
            l++; r--;
        } else {
            ans += min(l, r);
        }
    }
    cout << ans << '\n';
}

/*

*/