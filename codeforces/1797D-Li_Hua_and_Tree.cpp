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
constexpr LL MX = 1 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, imp[MX], par[MX], cost[MX], subt[MX];
vector<LL> adj[MX];
struct customcomp {
    bool operator()(const arr2 &a, const arr2 &b) const {
        return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
    }
};
set<arr2, customcomp> g[MX];

void init(LL u, LL p) {
    par[u] = p;
    cost[u] = imp[u];
    subt[u] = 1;
    for (LL v : adj[u]) {
        if (v == p) continue;
        init(v, u);
        cost[u] += cost[v];
        subt[u] += subt[v];
    }
}

void create(LL u, LL p) {
    for (LL v : adj[u]) {
        if (v == p) continue;
        create(v, u);
        g[u].insert({ subt[v], v });
    }
}

void rotate(LL u) {
    LL pu = par[u];
    auto it = g[u].begin();
    LL v = (*it)[1], vc = (*it)[0];
    g[pu].erase(g[pu].find({subt[u], u})); // removing curr to father
    g[u].erase(g[u].find({subt[v], v})); // removing curr to son
    // computing new costs
    subt[u] -= vc;
    subt[v] += subt[u];
    cost[u] -= cost[v];
    cost[v] += cost[u];
    g[pu].insert({subt[v], v}); // creating father to son
    g[v].insert({subt[u], u});
    // setting new parents
    par[u] = v;
    par[v] = pu;
}

void solve() {
    cin >> n >> m;
    for (LL i = 0; i < n; i++) {
        cin >> imp[i];
        adj[i].clear();
        g[i].clear();
    }
    for (LL i = 0; i < n-1; i++) {
        LL u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<arr2> qr;
    for (LL i = 0; i < m; i++) {
        LL a, b; cin >> a >> b; b--;
        qr.push_back({a, b});
    }
    init(0, -1);
    create(0, -1);
    for (auto q : qr) {
        LL u = q[1];
        if (q[0] == 1) {
            cout << cost[u] << '\n';
        } else {
            if (g[u].size() == 0 || u == 0) continue;
            rotate(u);
        }
    }
}

/*

*/



