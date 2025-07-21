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

long long n, m, k, q;

LL quadratic(LL mid, LL p) {
    return (mid/p + 1) / 2;
}

using lll = __int128;
void solve() {
    cin >> n >> m;
    vector<LL> p(n);
    for (LL i = 0; i < n; i++) {
        LL v; cin >> v;
        p[i] = v;
    }
    LL lo = 1, hi = m;
    LL ans = 0;
    vector<LL> tmp(n);
    while (lo < hi) {
        // mid is the limit delta
        LL mid = lo + (hi - lo)/2;
        lll cost = 0;
        LL ct = 0;
        bool flag = false;
        for (LL i = 0; i < n; i++) {
            LL units = quadratic(mid, p[i]);
            lll currp = ((__int128)units)*units*p[i];
            cost += currp;
            if (cost > m) {
                flag = true;
                break;
            }
            ct += units;
            tmp[i] = units;
        }
        for (LL i = 0; i < n; i++) {
            if (flag) break;
            lll nxtp = ((tmp[i]+1)*(__int128)(tmp[i]+1)-tmp[i]*(__int128)tmp[i])*p[i];
            if (nxtp == mid+1 && cost + nxtp <= m) {
                cost += nxtp;
                ct++;
            }
        }
        if (cost > m) {
            hi = mid-1;
        } else {
            lo = mid+1;
            ans = max(ans, ct);
        }
    }
    
    cout << (long long)ans << '\n';
}

/*

*/