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
constexpr LL MX = 3 * 1e6 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;

struct BitTrie {
    LL BSZ = 63;
    LL tr[MX][2], c[MX], idx = 1; // optional end[MX]

    void add_val(LL num, LL val) {
        LL u = 1;
        for (LL i = BSZ; i >= 0; i--) { // usually str.size()
            LL bit = (num >> i) & 1;
            if (!tr[u][bit]) {
                tr[u][bit] = ++idx;
            }
            u = tr[u][bit];
            c[u] += val;
        }
    }
    
    // Modify depending on question - currently max xor of num in trie
    LL get_xor(LL num) {
        LL u = 1;
        LL res = 0;
        for (LL i = BSZ; i >= 0; i--) {
            LL bit = !((num >> i) & 1);
            if (tr[u][bit] && c[tr[u][bit]] > 0) {
                u = tr[u][bit];
                res |= (bit << i);
            } else {
                u = tr[u][!bit];
                res |= (!bit << i);
            }
        }
        return num^res;
    }
};
BitTrie t;
void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    LL pxor = 0;
    t.add_val(0, 1);
    for (LL i = 0; i < n; i++) {
        pxor ^= a[i];
        t.add_val(pxor, 1);
        ans = max(ans, t.get_xor(pxor));
    }
    cout << ans << '\n';
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
