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

LL n, q;
LL par[MX], grp[MX], tin[MX], tout[MX], depth[MX], comp[MX], pos[MX], sz[MX];
bool vis[MX];
vector<LL> adj[MX], cycle;
LL timer = 0;
/*
    grp represents the connected component of cycles and trees
    comp represents the specific tree component itself
*/

void dfs(LL u) {
    tin[u] = ++timer;
    for (LL v : adj[u]) {
        if (comp[v] == v) continue;
        depth[v] = depth[u]+1;
        grp[v] = grp[u];
        comp[v] = comp[u];
        dfs(v);
    }
    tout[u] = ++timer;
}

void solve() {
    cin >> n >> q;
    for (LL i = 0; i < n; i++) {
        cin >> par[i]; 
        par[i]--;
        adj[par[i]].push_back(i);
    }

    // Initialisations
    for (LL i = 0; i < n; i++) {
        comp[i] = -1;
    }

    // Find cycle
    for (LL i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        LL u = i;
        // Arrives at cycle
        while (!vis[u]) {
            vis[u] = 1;
            u = par[u];
        }
        LL ct = 1;
        // Iterates through cycle again, setting values
        while (u != i || cycle.empty()) {
            cycle.push_back(u);
            grp[u] = i;
            pos[u] = ++ct;
            u = par[u];
        }
        LL cycle_size = cycle.size();
        for (auto &c : cycle) {
            timer = 0;
            sz[c] = cycle_size;
            comp[c] = c; // Note: this holds true if in cycle

            // dfs outwards from each node to the end of 
            // tree, propagating values throughout
            dfs(c);
        }
        
        cycle.clear();
    }
    LL a, b, tmp;
    for (LL i = 0; i < q; i++) {
        cin >> a >> b;
        a--; b--;

        LL ret = -1;
        // Same connected component
        if (grp[a] == grp[b]) {
            // If destination node is in cycle (100% reachable)
            if (grp[b] == b) {
                ret = depth[a];
                tmp = pos[b] - pos[comp[a]];
                if (tmp < 0) {
                    tmp = (pos[comp[a]] + sz[comp[a]]) - pos[b];
                }
                ret += tmp;
            } else {
                // dest is not in cycle, if dest is ancestor of
                // source -> subtract depths, otherwise, impos
                if (comp[a] == comp[b] && tin[a] <= tin[b] && tin[a] < tout[b]) {
                    ret = depth[a] - depth[b];
                }
            }
        }

        cout << ret << endl;
    }
}





