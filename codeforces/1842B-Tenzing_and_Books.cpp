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

LL n, m, k, x;

void solve() {
    cin >> n >> x;
    vector<int> a[3];
    int t;
    for (int i = 0; i < n; i++) { cin >> t; a[0].push_back(t); }
    for (int i = 0; i < n; i++) { cin >> t; a[1].push_back(t); }
    for (int i = 0; i < n; i++) { cin >> t; a[2].push_back(t); }

    int res = 0;
    for (int i = 0; i < 3; i++) {
        int j = 0;
        while (j < n && ((res|a[i][j])&x)==(res|a[i][j])) {
            res |= a[i][j];
            j++;
        }
    }
    if (res == x) cout << "Yes\n";
    else cout << "No\n";
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
