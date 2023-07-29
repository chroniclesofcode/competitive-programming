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
#define arr array<LL,2>

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n, vis[MX], seen[MX], dist[MX], ans = 0;
vector<arr> adj[MX];
/*

*/

LL dfs(LL u) {
    if (vis[u]) return 0;
    vis[u] = 1;

    LL ct = 0;

    for (arr v : adj[u]) {
        if (!vis[v[0]]) {
            ct += dfs(v[0]) + 2*v[1];
        }
    }
    return ct;
}

void dfs2(LL u, LL dis) {
    if (seen[u]) {
        return;
    }
    seen[u] = 1;
    dist[u] = dis;
    LL ct = 0;
    for (arr v : adj[u]) {
        if (!seen[v[0]]) {
            dfs2(v[0], dis+v[1]);
            ct++;
        }
    }
    if (ct == 0 && u != 0) {
        ans = max(ans, dist[u]);
    }
    return;
}

void solve() {
    cin >> n;
    LL x,y,z;
    for (LL i = 0; i < n-1; i++) {
        cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    LL tot = dfs(0);
    dfs2(0,0);
    cout << tot - ans << endl;
}





