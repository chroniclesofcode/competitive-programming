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
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;
LL h[1001][1001];
vector<LL> a, b;
const LL inf = LINF;

void debug(vector<LL>& dp) {
    LL dp0 = dp[0] >= inf ? -1 : dp[0];
    LL dp1 = dp[1] >= inf ? -1 : dp[1];
    cout << "dp: " << dp0 << ' ' << dp1 << endl;
}

// calculuate cost of row based operations on rows
// when passing in a column vector into here, make sure
// you transpose the h matrix
LL cost(vector<LL>& c) {
    vector<LL> dp(2);
    vector<LL> prev(2);
    // 0 is notake, 1 is take of the current
    for (LL i = 0; i < n; i++) {
        if (i == 0) {
            dp[0] = 0;
            dp[1] = c[i];
        } else {
            LL same = 0;
            LL has_higher = 0;
            LL has_lower = 0;
            for (LL j = 0; j < n; j++) {
                if (h[i][j] == h[i-1][j] - 1) {
                    has_higher = 1;
                }
                if (h[i][j] == h[i-1][j]) {
                    same = 1;
                }
                if (h[i][j] == h[i-1][j] + 1) {
                    has_lower = 1;
                }
            }
            dp[0] = inf;
            dp[1] = inf;
            if (!same) {
                dp[0] = prev[0];
                dp[1] = c[i] + prev[1];
                if (!has_higher) {
                    dp[1] = min(dp[1], c[i] + prev[0]);
                }
                if (!has_lower) {
                    dp[0] = min(dp[0], prev[1]);
                }
            } else {
                if (!has_higher) {
                    dp[1] = min(dp[1], c[i] + prev[0]);
                }
                if (!has_lower) {
                    dp[0] = min(dp[0], prev[1]);
                }
            }
        }
        swap(dp, prev);
    }
    return min(prev[0], prev[1]);
}

void solve() {
    a.clear(); b.clear();
    cin >> n;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            LL x; cin >> x;
            h[i][j] = x;
        }
    }
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        a.push_back(x);
    }
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        b.push_back(x);
    }
    LL cost1 = cost(a);
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < i; j++) {
            swap(h[i][j], h[j][i]);
        }
    }
    LL cost2 = cost(b);
    LL combined = cost1 + cost2;
    cout << (combined >= inf ? -1 : combined) << '\n';
}
/*
    sol: dp on vert and horizontal.
    up to i, need a TAKE or NOT TAKE this current column to satisfy
    the condition 0..i. We iterate through and see if there are any
    horizontal violators, if there is, we do a not take current row,
    which means it's the cost of must taking the previous row.
    otherwise, we take the current row, and not take the previous row.

    if there are NO violators, we might need the take for the next row
    anyways, so we do a TAKE on the current one + min of take/notake for
    the previous row, or a NOTAKE on the current one + min of take/notake. 
    Then, you do it for horizontal as well, and you're done!

    a will increase rows
    b will increase columns
    all by 1, their value represents their cost.
    Find minimum cost to make no two buildings have the same height.

    observations:
    - we need to identify all buildings which have adjacent same height, we will
    need to fix these one way or another. if they are same on the column, we will
    have to take the builder from either of the two rows. if they are on the same row,
    then we have to take either of column builders.
    - however, choosing one of these builders may actually cause other ones to become
    the same-adjacent, result in us needing to choose builders AGAIN. 
    - however, this loop should not go on forever since there are limited builders
    - this problem is unsolvable if say, there is a row which has two adjacent, but
    increasing the left column will make ANOTHER entry equal to the right col. Thus,
    we must take the right col, but what if that makes an equality with the left col?
    - if theyre staggered in a z pattern, you will need to either take the middle
    or the two edges

    - what it looks like is a DFS, every single element will need you to take 2 paths
    - you probably need to take all 2 paths, but that breaks time complexity possibly.
    - you can't say that taking the cheapest path is best, because taking an expensive
    path could actually have flow on effects that help out another path.
    - could you actually calculate this equity? So you calculate the cost of taking this
    path, how much does it actually save? if you take this path, and it cancels out
    another pair accidentally, what is the value? or should I not worry about the ten
    billion cases and find an algorithm that works pretty well for all of it?
*/