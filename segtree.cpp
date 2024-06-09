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
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 2 * 1e5;
constexpr int MD = (int)1e9 + 7;

LL n, q;

class SegtreePNode {
public:
    using LL = long long;
    LL n = 0;
    
    struct node {
        LL x;
        node() : x{0} {}
        node(int e) : x{e} {}

        friend node operator+(const node &a, const node &b) {
            return node(a.x + b.x);
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

// Range update, Range query -> can  be used in most applications
class SegmentTree {
private:
    int n;
    vector<long long> segtree;
    vector<long long> lazy;
public:
    SegmentTree(int sz) : n{sz} {
        segtree.resize(1 + 4 * sz);
        lazy.resize(1 + 4 * sz);
    }

    void build(int node, int L, int R, vector<int> &v) {
        if(L == R) {
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

class Segtree2Ranges {
public:
    int maxN = 0;
    using ll = long long;

    struct node {
        ll val;
        ll lzAdd;
        ll lzSet;
        node(){};
    };

    vector<node> tree;

    Segtree2Ranges(int n) : maxN(n), tree(n*4 + 1) {}

    #define lc p << 1
    #define rc (p << 1) + 1

    inline void pushup(int p) {
        tree[p].val = tree[lc].val + tree[rc].val;
        return;
    }

    void pushdown(int p, int l, int mid, int r) {
        // lazy: range set
        if (tree[p].lzSet != 0) {
            tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
            tree[lc].val = (mid - l + 1) * tree[p].lzSet;
            tree[rc].val = (r - mid) * tree[p].lzSet;
            tree[lc].lzAdd = tree[rc].lzAdd = 0;
            tree[p].lzSet = 0;
        } else if (tree[p].lzAdd != 0) {  // lazy: range add
            if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
            else {
                tree[lc].lzSet += tree[p].lzAdd;
                tree[lc].lzAdd = 0;
            }
            if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
            else {
                tree[rc].lzSet += tree[p].lzAdd;
                tree[rc].lzAdd = 0;
            }
            tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
            tree[rc].val += (r - mid) * tree[p].lzAdd;
            tree[p].lzAdd = 0;
        }
        return;
    }


    void add(int p, int l, int r, int a, int b, ll val) {
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            tree[p].val += (r - l + 1) * val;
            if (tree[p].lzSet == 0) tree[p].lzAdd += val;
            else tree[p].lzSet += val;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(p, l, mid, r);
        add(lc, l, mid, a, b, val);
        add(rc, mid + 1, r, a, b, val);
        pushup(p);
        return;
    }

    void set(int p, int l, int r, int a, int b, ll val) {
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            tree[p].val = (r - l + 1) * val;
            tree[p].lzAdd = 0;
            tree[p].lzSet = val;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(p, l, mid, r);
        set(lc, l, mid, a, b, val);
        set(rc, mid + 1, r, a, b, val);
        pushup(p);
        return;
    }

    ll query(int p, int l, int r, int a, int b) {
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return tree[p].val;
        int mid = (l + r) >> 1;
        pushdown(p, l, mid, r);
        return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
    }
};

// Adding on segments, querying for maximum
void solve() {
    cin >> n;
    LL x;
    //SegtreeRange s(n);
    SegtreePNode s(n);
    for (LL i = 0; i < n; i++) {
        cin >> x;
        //s.update(i, i, x);
        s.update(i, x);
    }
    s.update(3, 69);
    cout << s.query(1, 3).x << '\n';
}


// NORMAL SEGTREES, NODE IS PROBABLY BETTER.

class SegtreePoint {
public:
    using LL = long long;
    LL n = 0;
    vector<LL> t;

    SegtreePoint(LL sz) : n(sz), t(4 * sz + 1) {}

    LL query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return 0;
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

class SegtreeRange {
public:
    using LL = long long;
    LL n = 0;
    vector<LL> t, lazy;
    SegtreeRange(LL sz) : n{sz}, t(4*sz+1), lazy(4*sz+1) {}


    void push(LL v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void update(LL l, LL r, LL addend, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            LL tm = (tl + tr) / 2;
            update(l, min(r, tm), addend, v*2, tl, tm);
            update(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    LL query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r)
            return -INF;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        LL tm = (tl + tr) / 2;
        return max(query(l, min(r, tm), v*2, tl, tm), 
                   query(max(l, tm+1), r, v*2+1, tm+1, tr));
    }
};
