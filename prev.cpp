#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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

LL n, m, k, q;

class FenwickArr {
public:
    LL n;
    vector<LL> BIT;
    vector<LL> arr;

    FenwickArr(LL sz) : n{sz}, BIT(sz+1, 0), arr(sz) {}

    void add(LL x, LL add) {
        arr[x] += add;
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    LL query(LL x) {
        x++;
        LL sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }

    void set(LL idx, LL val) {
        add(idx, val - arr[idx]);
    }

    LL pref(LL st, LL end) {
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

void solve() {
    cin >> n >> q;
    vector<LL> a(n);
    FenwickArr pf(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        pf.add(i, a[i]);
    }
    vector<vector<arr2>> queries(n);
    for (LL i = 0; i < q; i++) {
        LL x, y; cin >> x >> y; x--; y--;
        queries[x].push_back({y, i});
    }
    FenwickArr f(n);
    vector<arr2> st;
    vector<LL> ans(q);
    for (LL i = n-1; i >= 0; i--) {
        LL val = a[i];
        while (!st.empty() && st.back()[0] <= val) {
            st.pop_back();
            f.set(st.size(), 0);
        }
        LL len = (st.empty() ? n : st.back()[1]) - i;
        st.push_back({val, i});
        f.set(st.size()-1, len * a[i]);
        for (auto &qu : queries[i]) {
            LL y = qu[0];
            LL lo = 0, hi = st.size()-1;
            LL elem = -1;
            // Looking for element in stack that finishes
            // before y in x->y.
            while (lo <= hi) {
                LL mid = lo + (hi - lo)/2;
                // Compares index NOT value. Everything
                // in stack is already guaranteed to be
                // larger.
                if (st[mid][1] <= y) {
                    elem = mid;
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            }
            // Note: elem+1 since our pref sum is inclusive
            // exclude the elem, and calculate it manually
            ans[qu[1]] = f.pref(elem+1, st.size()-1)
                + (LL)((y - st[elem][1]+1)*st[elem][0])
                - pf.pref(i, y);
        }
    }
    for (auto e : ans) cout << e << '\n';
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
