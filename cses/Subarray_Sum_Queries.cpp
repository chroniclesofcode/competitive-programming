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

class SegtreePNode {
public:
    LL n = 0;
    
    struct node {
        LL x[2][2];
        node() {}
        node(LL e) {
            x[0][0] = x[1][0] = x[0][1] = 0;
            x[1][1] = e;
        }

        friend node operator+(const node &a, const node &b) {
            node ret;
            ret.x[0][0] = max({a.x[0][1]+b.x[1][0], a.x[0][1],b.x[0][1],a.x[0][0],b.x[0][0]});
            ret.x[1][0] = max({a.x[1][0],a.x[1][1],a.x[1][1]+b.x[1][0]});
            ret.x[0][1] = max({a.x[0][1]+b.x[1][1],b.x[0][1],b.x[1][1]});
            ret.x[1][1] = a.x[1][1] + b.x[1][1];
            return ret;
        }
    };

    vector<node> t;

    SegtreePNode(LL sz) : n(sz), t(4 * sz + 1) {}

    node query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return node();
        if (l == tl && r == tr) {
            return t[v];
        }
        LL tm = (tl + tr) / 2;
        return query(l, min(r, tm), v * 2, tl, tm) +
               query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }

    void update(LL pos, LL new_val, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            t[v] = new_val;
        } else {
            LL tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, new_val, v * 2, tl, tm);
            else
                update(pos, new_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

void solve() {
    cin >> n >> m;
    SegtreePNode s(n);
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x; s.update(i, x);
    }
    for (LL i = 0; i < m; i++) {
        LL k, x; cin >> k >> x; k--;
        s.update(k, x);
        auto e = s.query(0, n-1);
        cout << max({e.x[0][0],e.x[1][0],e.x[0][1],e.x[1][1]}) << '\n';
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
