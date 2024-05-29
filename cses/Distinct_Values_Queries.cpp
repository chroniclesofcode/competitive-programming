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

LL n, m, k, q;

class Fenwick {
public:
    int n;
    vector<int> BIT;

    Fenwick(int sz) : n{sz}, BIT(sz+1, 0) {}

    void add(int x, int add) {
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    int query(int x) {
        x++;
        int sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }
};

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<arr2>> queries(n);
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--; y--;
        queries[x].push_back({y, i});
    }
    map<int, int> mp;
    Fenwick f(n);
    vector<int> ans(q);
    for (int i = n-1; i >= 0; i--) {
        int val = a[i];
        auto it = mp.find(val);
        if (it != mp.end()) f.add(it->second, -1);
        mp[val] = i;
        f.add(i, 1);
        for (auto &qu : queries[i]) {
            ans[qu[1]] = f.query(qu[0]);
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
