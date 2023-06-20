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

const LL MX = 2 * 1e5;
//const LL MOD = 1e7;

int n, m, grp[MX];
vector<int> adj[MX], rev[MX], scc[MX];
vector<bool> vis(MX, false);
vector<int> order, comp, rts;
/*

*/

void dfs1(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp.push_back(u);
    for (auto &v : rev[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    vis.assign(n, false);

    reverse(order.begin(), order.end());

    for (auto &v : order) {
        if (!vis[v]) {
            dfs2(v);

            int rt = comp.front();
            for (auto &u : comp) {
                grp[u] = rt;
            }
            rts.push_back(rt);

            comp.clear();
        }
    }

    for (int i = 0; i < n; i++) {
        int r1 = grp[i];
        for (auto &u : adj[i]) {
            int r2 = grp[u];
            if (r1 != r2) {
                scc[r1].push_back(r2);
            }
        }
    }

}





