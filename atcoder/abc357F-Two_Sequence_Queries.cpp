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

class SegmentTree {
public:
    struct node {
        long long suma = 0, sumb = 0, sumab = 0, 
                  lazya = 0, lazyb = 0;
    };

    LL n;
    vector<node> segtree;
    SegmentTree() {}
    SegmentTree(LL sz) : n{sz} {
        segtree.resize(1 + 4 * sz);
    }

    void build(LL node, LL L, LL R, vector<long long> &av, vector<long long> &bv) {
        if(L == R) {
            segtree[node].suma = av[L] % MD;
            segtree[node].sumb = bv[L] % MD;
            segtree[node].sumab = (av[L] * bv[L]) % MD;
            return;
        }
        LL mid = (L + R) / 2;
        build(node*2, L, mid, av, bv);
        build(node*2+1, mid+1, R, av, bv);
        segtree[node].suma = (segtree[node*2].suma + segtree[node*2+1].suma) % MD;
        segtree[node].sumb = (segtree[node*2].sumb + segtree[node*2+1].sumb) % MD;
        segtree[node].sumab = (segtree[node*2].sumab + segtree[node*2+1].sumab) % MD;
    }

    void lz(LL node, LL L, LL R) {
        auto &seg = segtree[node];
        seg.sumab = (seg.sumab + seg.lazya * seg.sumb) % MD;
        seg.sumab = (seg.sumab + seg.suma * seg.lazyb) % MD;
        seg.sumab += (((seg.lazya%MD) * (seg.lazyb%MD))%MD) * ((R-L+1) %MD);
        seg.sumab %= MD;
        if (L != R) {
            auto &segl = segtree[node*2];
            auto &segr = segtree[node*2+1];
            segl.lazya = (segl.lazya + seg.lazya) % MD;
            segr.lazya = (segr.lazya + seg.lazya) % MD;
            segl.lazyb = (segl.lazyb + seg.lazyb) % MD;
            segr.lazyb = (segr.lazyb + seg.lazyb) % MD;
        }
        seg.suma += seg.lazya * ((R - L + 1)%MD);
        seg.sumb += seg.lazyb * ((R - L + 1)%MD);
        seg.suma %= MD;
        seg.sumb %= MD;
        seg.lazya = 0;
        seg.lazyb = 0;
    }

    void update(LL node, LL L, LL R, LL Lq, LL Rq, long long adda, long long addb) {
        if (segtree[node].lazya || segtree[node].lazyb)
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return;
        if (Lq <= L && R <= Rq) {
            segtree[node].lazya += adda;
            segtree[node].lazyb += addb;
            segtree[node].lazya %= MD;
            segtree[node].lazyb %= MD;
            lz(node, L, R);
            return;
        }
        LL mid = (L + R) / 2;
        update(node*2, L, mid, Lq, Rq, adda, addb);
        update(node*2+1, mid+1, R, Lq, Rq, adda, addb);

        segtree[node].suma = (segtree[node*2].suma + segtree[node*2+1].suma) % MD;
        segtree[node].sumb = (segtree[node*2].sumb + segtree[node*2+1].sumb) % MD;
        segtree[node].sumab = (segtree[node*2].sumab + segtree[node*2+1].sumab) % MD;

    }

    long long query(LL node, LL L, LL R, LL Lq, LL Rq) {
        if (segtree[node].lazya || segtree[node].lazyb)
            lz(node, L, R);
        if (R < Lq || L > Rq)
            return 0;
        if (Lq <= L && R <= Rq)
            return (segtree[node].sumab % MD);
        LL mid = (L + R) / 2;
        return (query(node*2, L, mid, Lq, Rq) + query(node*2+1, mid+1, R, Lq, Rq)) % MD;
    }
};

void solve() {
    LL queries;
    cin >> n >> queries;
    vector<long long> a(n), b(n);
    for (LL i = 0; i < n; i++) cin >> a[i];
    for (LL i = 0; i < n; i++) cin >> b[i];
    SegmentTree s(n);
    s.build(1, 0, n-1, a, b);
    for (LL q = 0; q < queries; q++) {
        long long op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x; l--; r--;
            s.update(1, 0, n-1, l, r, x, 0);
        } else if (op == 2) {
            cin >> l >> r >> x; l--; r--;
            s.update(1, 0, n-1, l, r, 0, x);
        } else {
            cin >> l >> r; l--; r--;
            cout << (s.query(1, 0, n-1, l, r)%MD+MD)% MD << '\n';
        }
    }
}

/*
4 5
1000000000 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000
1 1 4 1000000000
1 1 4 1000000000
1 1 4 1000000000
1 1 4 1000000000
3 1 4

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
