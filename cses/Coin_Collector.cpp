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

const LL MX = 2 * 1e5 + 20;
//const LL MOD = 1e7;

LL n, m, grp[MX], cost1[MX], cost[MX], dp[MX], indeg[MX];
vector<LL> adj[MX], rev[MX], scc[MX], rscc[MX];
vector<bool> vis(MX, false);
vector<LL> order, comp, rts;
/*

*/

void dfs1(LL u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(LL u) {
    vis[u] = true;
    comp.push_back(u);
    for (auto &v : rev[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

void dfs3(LL u) {
}

void solve() {
    cin >> n >> m;

    LL a, b;
    for (LL i = 0; i < n; i++) {
        cin >> cost1[i];
    }
    for (LL i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (LL i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    vis.assign(n, false);

    reverse(order.begin(), order.end());

    for (auto &v : order) {
        if (!vis[v]) {
            dfs2(v);

            LL rt = comp.front();
            LL tmpc = 0;
            for (auto &u : comp) {
                grp[u] = rt;
                tmpc += cost1[u];
            }
            rts.push_back(rt);
            cost[rt] = tmpc;

            comp.clear();
        }
    }

    for (LL i = 0; i < n; i++) {
        LL r1 = grp[i];
        for (auto &u : adj[i]) {
            LL r2 = grp[u];
            if (r1 != r2) {
                scc[r1].push_back(r2);
                rscc[r2].push_back(r1);
                indeg[r2]++;
            }
        }
    }

    queue<LL> q;
    for (auto &r : rts) {
        dp[r] = cost[r];
        if (indeg[r] == 0) {
            q.push(r);
        }
    }
    LL ans = 0;
    while (!q.empty()) {
        LL u = q.front();
        q.pop();

        for (auto &v : scc[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
        for (auto &v : rscc[u]) {
            dp[u] = max(dp[u], dp[v] + cost[u]);
        }
        ans = max(ans, dp[u]);
    }
    cout << ans << endl;

}





