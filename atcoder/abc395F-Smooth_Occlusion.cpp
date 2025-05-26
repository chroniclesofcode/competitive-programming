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

LL n, m, k, q, x;

// conditions:
// sum of same i is H for ALL i
// difference between upper is <= x
// min ops to: reduce one tooth length

void solve() {
    cin >> n >> x;
    LL lo = 0, hi = LINF;
    vector<LL> u(n), d(n);
    for (LL i = 0; i < n; i++) {
        LL x, y; cin >> x >> y;
        u[i] = x;
        d[i] = y;
        hi = min(hi, x + y);
    }
    LL ans = LINF;
    while (lo <= hi) {
        LL H = lo + (hi - lo)/2;
        // second binary search, searches top of the
        // range. It only needs to be as big as H.
        LL possible = 1;
        LL cost = 0;

        // maintain ranges on possible values each upper
        // tooth can take
        LL lowerb = 0, upperb = LINF;
        for (LL i = 0; i < n; i++) {
            LL top = u[i], bot = d[i];
            LL rem = (top+bot) - H;
            cost += rem;
            // we have to remove at least force_u amount
            // from the top
            LL force_u = max(0LL, rem - bot);
            top -= force_u;
            rem -= force_u;

            LL curr_hi = top;
            LL curr_lo = max(0LL, top - rem);
            
            upperb = min(curr_hi, upperb + x);
            lowerb = max(curr_lo, lowerb - x);
            if (lowerb > curr_hi || upperb < curr_lo)  {
                possible = 0;
                break;
            }
        }
        if (possible) {
            ans = min(ans, cost);
            lo = H+1;
        } else {
            hi = H-1;
        }
    }
    cout << ans << '\n';
}

/*
    binary search for the integer H, since if successful, we
    go up. If not, we go down. It is monotonic since the lower
    we go, the more chance we can shave all the U's down.

    Then, after a bit of manipulation, we have this subproblem.
    We have N integers and for each one, an associated rem value.
    We can remove 0..rem from each of the integers (note rem can be
    > than N), is it possible to make ADJACENT values within X?
*/