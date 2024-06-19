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
vector<int> adj[MX];
int val[MX], idx[MX], subt[MX];
vector<int> order;

void dfs(int u, int p) {
    order.push_back(u);
    subt[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subt[u] += subt[v];
    }
}

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
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

void solve() {
    int queries;
    cin >> n >> queries; 
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    FenwickArr f(n);
    for (int i = 0; i < order.size(); i++) {
        idx[order[i]] = i;
        f.set(i, val[order[i]]);
    }
    for (int i = 0; i < queries; i++) {
        int op, s, x; cin >> op;
        if (op == 1) {
            cin >> s >> x; s--;
            f.set(idx[s], x);
        } else if (op == 2) {
            cin >> s; s--;
            cout << f.pref(idx[s], idx[s]+subt[s]-1) << '\n';
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
