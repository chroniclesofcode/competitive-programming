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

LL n, m, k, sz[MX];
vector<LL> adj[MX];

int dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    return sz[u];
}

int centroid(int u, int p, int tot) {
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sz[v] > tot / 2) return centroid(v, u, tot);
    }
    return u;
}

void solve() {
    cin >> n; 
    for (LL i = 0; i < n-1; i++) {
        LL a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << centroid(0, -1, n)+1 << '\n';
}

