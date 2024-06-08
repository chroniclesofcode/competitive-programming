#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

// Range update, Range query -> can  be used in most applications
class SegmentTree {
private:
    int n;
    vector<long long> segtree;
    vector<long long> lazy;
public:
    SegmentTree() {}

    SegmentTree(int sz) : n{sz} {
        segtree.resize(1 + 4 * sz);
        lazy.resize(1 + 4 * sz);
    }

    void build(int node, int L, int R, vector<int> &v) {
        if (L == R) {
            segtree[node] = v[L];
            return;
        }
        int mid = (L + R) / 2;
        build(node*2, L, mid, v);
        build(node*2+1, mid+1, R, v);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    void lz(int node, int L, int R) {
        segtree[node] += lazy[node] * (R - L + 1);
        if (L != R) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int node, int L, int R, int Lq, int Rq, int val) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return;
        if (Lq <= L && R <= Rq) {
            lazy[node] = val;
            lz(node, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update(node*2, L, mid, Lq, Rq, val);
        update(node*2+1, mid+1, R, Lq, Rq, val);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    long long query(int node, int L, int R, int Lq, int Rq) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return 0;
        if (Lq <= L && R <= Rq)
            return segtree[node];
        int mid = (L + R) / 2;
        return query(node*2, L, mid, Lq, Rq) + query(node*2+1, mid+1, R, Lq, Rq);
    }

    void op1(int l, int r, int x) {
    }

    void op2(int l, int r, int x) {
    }
};



// Range update, Range query -> can  be used in most applications
class Ans {
private:
    int n;
    vector<long long> segtree;
    vector<long long> lazy;
    SegmentTree a, b;
public:
    Ans(int sz, vector<int> &av, vector<int> &bv) : n{sz} {
        segtree.resize(1 + 4 * sz);
        lazy.resize(1 + 4 * sz);
        a = SegmentTree(sz);
        b = SegmentTree(sz);
        a.build(1, 0, sz-1, av);
        b.build(1, 0, sz-1, bv);
    }

    void build(int node, int L, int R, vector<int> &v) {
        if (L == R) {
            segtree[node] = v[L];
            return;
        }
        int mid = (L + R) / 2;
        build(node*2, L, mid, v);
        build(node*2+1, mid+1, R, v);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    void lz(int node, int L, int R) {
        segtree[node] += lazy[node] * (R - L + 1);
        if (L != R) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int node, int L, int R, int Lq, int Rq, int val) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return;
        if (Lq <= L && R <= Rq) {
            lazy[node] = val;
            lz(node, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update(node*2, L, mid, Lq, Rq, val);
        update(node*2+1, mid+1, R, Lq, Rq, val);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    long long query(int node, int L, int R, int Lq, int Rq) {
        if (lazy[node])
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return 0;
        if (Lq <= L && R <= Rq)
            return segtree[node];
        int mid = (L + R) / 2;
        return query(node*2, L, mid, Lq, Rq) + query(node*2+1, mid+1, R, Lq, Rq);
    }
};




void solve() {
    int q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    Ans s(n, a, b);
    for (int i = 0; i < q; i++) {
        int op, l, r, x;
        if (op == 1) {
            cin >> l >> r >> x; l--; r--;
            a.op1(l, r, x);
        } else if (op == 2) {
            cin >> l >> r >> x; l--; r--;
            a.op2(l, r, x);
        } else {
            cin >> l >> r;
            cout << a.query(l, r) << '\n';
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
