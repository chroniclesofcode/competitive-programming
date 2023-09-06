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

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, sbt[MX], dist[MX], ret[MX];
vector<LL> adj[MX];
/*
    find depths of all nodes, then bfs calc all sums
    by looking at parent -> parents dist to all nodes
    - nodes in subtree + 1.
*/

LL dfs(LL u, LL p, LL dep) {
    LL sm = dep;
    sbt[u] = 1;
    for (LL v : adj[u]) {
        if (v != p) {
            sm += dfs(v, u, dep+1);
            sbt[u] += sbt[v];
        }
    }
    dist[u] = sm;
    return sm;
}

void dfs2(LL u, LL p, LL pval) {
    LL excl = n - sbt[u];
    ret[u] = pval + excl - sbt[u];
    for (LL v : adj[u]) {
        if (v != p) {
            dfs2(v, u, ret[u]);
        }
    }
}

void solve() {
    cin >> n;
    for (LL i = 0; i < n-1; i++) {
        LL a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LL tp = dfs(0, -1, 0);
    ret[0] = tp;
    for (auto v : adj[0]) {
        dfs2(v, 0, tp);
    }
    for (LL i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << endl;
}





