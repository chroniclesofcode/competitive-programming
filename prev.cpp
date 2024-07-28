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
    cin >> n >> q;
    vector<LL> a;
    vector<LL> ans(q);
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    LL b;
    for (LL i = 0; i < q; i++) {
        cin >> b >> k;
        auto it = upper_bound(a.begin(), a.end(), b);
        auto st = it;
        if (it != a.begin()) {
            it--;
            if (st == a.end()) {
                st = it;
            } else if (abs(*it - b) < abs(*st - b)) {
                st = it;
            }
        }
        if (k == 1) {
            cout << abs(*st-b) << '\n'; continue;
        }
        LL lo = abs(b-*st), hi = INF;
        LL ans = INF;
        LL cid = st - a.begin();
        while (lo <= hi) {
            LL mid = lo + (hi-lo)/2;
            LL above = b + mid, below = b - mid; 
            auto fr = upper_bound(a.begin(), a.end(), above);
            auto bk = lower_bound(a.begin(), a.end(), below);
            LL frid = fr-a.begin(), bkid = bk-a.begin();
            LL ct = fr - bk;
            //cout << "b: " << b << " k: " << k << " mid: " << mid << " ct: " << ct << '\n';
            if (ct >= k) {
                hi = mid-1;
                LL c1 = abs(*bk-b);
                LL c2 = INF;
                if (fr != bk && fr != a.begin()) {
                    fr--;
                    c2 = abs(*fr-b);
                }
                ans = min(ans, max(c1,c2));
            } else if (ct < k) {
                lo = mid+1;
            }
        }
        cout << ans << '\n';
    }
}

/*
   0 1 2 | 3
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

