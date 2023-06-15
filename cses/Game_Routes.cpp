#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e6;
const LL MOD = 1e9 + 7;

LL n, m;
vector<LL> adj[MX];
LL dist[MX];
bool vis[MX];
/*

*/

void dfs(LL u) {
    dist[u] = u == n-1 ? 1 : 0;
    vis[u] = 1;

    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
        dist[u] += dist[v];
        dist[u] %= MOD;
    }
}

void solve() {
    cin >> n >> m;
    LL t1,t2;
    for (LL i = 0; i < m; i++) {
        cin >> t1 >> t2;
        adj[t1-1].push_back(t2-1);
    }

    dfs(0);
    if (dist[0] < 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dist[0] << endl;
}





