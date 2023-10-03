#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 2001;
//const LL MOD = 1e7;

int n, m, vis[MX], deg[MX], iscyc, orig;
vector<int> adj[MX];

/*

*/

void dfs(int u) {
    if (orig == u) {
        iscyc = 1;
        return;
    }
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        iscyc = 0;
        orig = i;
        if (deg[i] >= 4) {
            dfs(i);
        }
    }
}





