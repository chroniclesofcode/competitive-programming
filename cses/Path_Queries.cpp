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
vector<LL> adj[MX];
LL val[MX], idx[MX], subt[MX];
vector<LL> order;

void dfs(LL u, LL p) {
    if (p != -1) {
        val[u] += val[p];
    }
    order.push_back(u);
    subt[u] = 1;
    for (LL v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subt[u] += subt[v];
    }
}

class SegmentTree {
private:
    LL n;
    vector<long long> segtree;
    vector<long long> lazy;
public:
    SegmentTree() {}
    SegmentTree(LL sz) : n{sz} {
        segtree.resize(1 + 4 * sz);
        lazy.resize(1 + 4 * sz);
    }

    void build(LL node, LL L, LL R, vector<LL> &v) {
        if(L == R) {
            segtree[node] = v[L];
            return;
        }
        LL mid = (L + R) / 2;
        build(node*2, L, mid, v);
        build(node*2+1, mid+1, R, v);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    void lz(LL node, LL L, LL R) {
        segtree[node] += lazy[node] * (R - L + 1);
        if (L != R) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(LL node, LL L, LL R, LL Lq, LL Rq, LL val) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return;
        if (Lq <= L && R <= Rq) {
            lazy[node] = val;
            lz(node, L, R);
            return;
        }
        LL mid = (L + R) / 2;
        update(node*2, L, mid, Lq, Rq, val);
        update(node*2+1, mid+1, R, Lq, Rq, val);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    long long query(LL node, LL L, LL R, LL Lq, LL Rq) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return 0;
        if (Lq <= L && R <= Rq)
            return segtree[node];
        LL mid = (L + R) / 2;
        return query(node*2, L, mid, Lq, Rq) + query(node*2+1, mid+1, R, Lq, Rq);
    }
};

void solve() {
    LL queries;
    cin >> n >> queries; 
    vector<LL> tmp(n);
    for (LL i = 0; i < n; i++) {
        cin >> val[i];
        tmp[i] = val[i];
    }
    for (LL i = 0; i < n-1; i++) {
        LL a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    SegmentTree seg(n);
    for (LL i = 0; i < order.size(); i++) {
        idx[order[i]] = i;
        seg.update(1, 0, n-1, i, i, val[order[i]]);
    }
    for (LL i = 0; i < queries; i++) {
        LL op, s, x; cin >> op;
        if (op == 1) {
            cin >> s >> x; s--;
            LL delta = x - tmp[s];
            seg.update(1, 0, n-1, idx[s], idx[s]+subt[s]-1, delta);
            tmp[s] = x;
        } else if (op == 2) {
            cin >> s; s--;
            cout << seg.query(1, 0, n-1, idx[s], idx[s]) << '\n';
        }
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
