#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prt_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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

LL n, m, k, sz[MX], rem[MX], ans[MX];
vector<LL> adj[MX];
vector<pair<LL,LL>> anc[MX]; // { ancestor, distance }

LL get_subt(LL u, LL p) {
    sz[u] = 1;
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        sz[u] += get_subt(v, u);
    }
    return sz[u];
}

LL centroid(LL u, LL p, LL tot) {
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        if (sz[v] >= tot/2) return centroid(v, u, tot);
    }
    return u;
}

void process_subt(LL u, LL p, LL c, LL dep) {
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        dep++;
        process_subt(v, u, c, dep);
        dep--;
    }
    anc[u].push_back({c, dep});
}

void centroid_decomp(LL node = 0) {
    LL c = centroid(node, -1, get_subt(node, -1));
    rem[c] = true;
    
    // Add logic here
    for (LL v : adj[c]) {
        if (rem[v]) continue;
        process_subt(v, c, c, 1);
    }

    for (LL v : adj[c]) {
        if (rem[v]) continue;
        centroid_decomp(v);
    }
}

void paint(int u) {
    for (auto &[a, dep] : anc[u]) {
        ans[a] = min(ans[a], dep);
    }
    ans[u] = 0; // current is 0
}

void solve() {
    cin >> n >> m; 
    for (LL i = 0; i < n-1; i++) {
        LL a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) ans[i] = INF;

    centroid_decomp(0);
    paint(0);
    for (int i = 0; i < m; i++) {
        int op, v; cin >> op >> v; v--;
        if (op == 1) {
            // paint v red
            paint(v);
        } else {
            // shortest distance to red from v
            LL ret = ans[v];
            for (auto &[a, dep] : anc[v]) {
                ret = min(ret, dep + ans[a]);
            }
            cout << ret << '\n';
        }
    }
}


