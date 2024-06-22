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

LL n, m, k;


void solve() {
    cin >> n;
    vector<LL> h(n+1);
    h[0] = INF;
    for (LL i = 1; i <= n; i++) {
        cin >> h[i];
    }
    stack<LL> s;
    s.push(0);
    vector<LL> ans(n+1);
    for (LL i = 1; i <= n; i++) {
        while (!s.empty() && h[s.top()] < h[i]) {
            s.pop();
        }
        LL tp = s.top();
        ans[i] = ((i - tp) * h[i]) + 1;
        if (tp > 0) ans[i] += ans[tp] - 1;
        s.push(i);
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

