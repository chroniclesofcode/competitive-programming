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


void solve() {
    int q;
    cin >> n >> q;
    vector<int> a(n);
    Segtree2Ranges s(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) s.set(1, 0, n-1, i, i, a[i]);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, val; cin >> x >> y >> val; x--; y--;
            s.add(1, 0, n-1, x, y, val);
        } else if (op == 2) {
            int x, y, val; cin >> x >> y >> val; x--; y--;
            s.set(1, 0, n-1, x, y, val);
        } else {
            int x, y; cin >> x >> y; x--; y--;
            cout << s.query(1, 0, n-1, x, y) << '\n';
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
