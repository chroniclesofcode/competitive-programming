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

class SegmentTree {
private:
    LL n;
    vector<long long> segtree;
    vector<array<long long,2>> lazy;
public:
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
        LL len = R - L + 1;
        LL start = lazy[node][0], inc = lazy[node][1];
        segtree[node] += len*start + (len-1)*inc*len/2;
        if(L != R) {
            lazy[node*2][0] += start;
            lazy[node*2][1] += inc;
            LL mid = (R+L)/2;
            lazy[node*2+1][0] += start + (mid-L+1)*inc;
            lazy[node*2+1][1] += inc;
        }
        lazy[node] = {0,0};
    }

    void update(LL node, LL L, LL R, LL Lq, LL Rq, LL val) {
        if(lazy[node][0])
            lz(node, L, R);
        if(R < Lq || L > Rq)
            return;
        if(Lq <= L && R <= Rq) {
            lazy[node][0] += val + (L - Lq);
            lazy[node][1] += 1;
            lz(node, L, R);
            return;
        }
        LL mid = (L + R) / 2;
        update(node*2, L, mid, Lq, Rq, val);
        update(node*2+1, mid+1, R, Lq, Rq, val);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
    }

    long long query(LL node, LL L, LL R, LL Lq, LL Rq) {
        if(lazy[node][0])
            lz(node, L, R);
        if(R < Lq || L > Rq)
            return 0;
        if(Lq <= L && R <= Rq)
            return segtree[node];
        LL mid = (L + R) / 2;
        return query(node*2, L, mid, Lq, Rq) + query(node*2+1, mid+1, R, Lq, Rq);
    }
};

void solve() {
    LL q;
    cin >> n >> q;
    vector<LL> t(n);
    SegmentTree s(n);
    for (LL i = 0; i < n; i++) {
        cin >> t[i];
    }
    s.build(1, 0, n-1, t);
    for (LL i = 0; i < q; i++) {
        LL op, a, b;
        cin >> op >> a >> b;
        a--; b--;
        if (op == 1) {
            // Increase
            s.update(1, 0, n-1, a, b, 1);
        } else {
            // Calc sum and output
            cout << s.query(1, 0, n-1, a, b) << '\n';
        }
    }
}

/*
The only thing you need to merge two ranges is
(starting add value of the range, current increment)
By starting value, if we are doing range 1->4, and we are
processing (3->4), the starting value will be 3 with inc 1.
also:
len/2 * (2*start + (len-1)*step)
len*start + (len-1)*step*len/2

1->4
st 1, inc 2
(1,2)(3,4)
1, 3, 5, 7
mid: 2
1 + (2-1+1)*2

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
