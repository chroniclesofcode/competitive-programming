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

LL n, m, k;


void solve() {
    cin >> n;
    vector<arr2> iv;
    vector<LL> ans(n);
    LL tot = 0;
    for (LL i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        iv.push_back({l,r});
        tot += l;
        ans[i] = l;
    }
    if (tot > 0) {
        cout << "No\n";
        return;
    }
    for (LL i = 0; i < n; i++) {
        LL l = iv[i][0], r = iv[i][1];
        if (tot < 0) {
            LL delta = min(-tot, (LL)r-l);
            tot += delta;
            ans[i] += delta;
        } 
        if (tot == 0) break;
    }

    if (tot == 0) {
        cout << "Yes\n";
        for (auto a : ans) cout << a << ' '; cout << '\n';
    } else {
        cout << "No\n";
    }
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

