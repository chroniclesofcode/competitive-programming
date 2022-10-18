#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 3 * 1e5 + 10;
vector<int> g[MX];
set<int> adj[MX];
vector<int> rev[MX];
bool used[MX];
vector<bool> vis;
vector<int> order, comp;

void dfs0(int v, int parent) {
    if (used[v]) return;
    used[v] = true;
    if (parent != 0 && !adj[v].count(parent)) {
        adj[parent].insert(v);
        rev[v].push_back(parent);
    }
    
    for (int u : g[v]) {
        if (u == v || u == parent) continue;
        if (used[u] && !adj[u].count(v)) {
            adj[v].insert(u);
            rev[u].push_back(v);
        } else {
            dfs0(u, v);
        }
    }
}

void dfs1(int v) {
    vis[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) 
        if (!vis[*it])
            dfs1(*it);

    order.push_back(v);
}

void dfs2(int v) {
    vis[v] = true;
    comp.push_back(v);

    for (auto u : rev[v])
        if (!vis[u])
            dfs2(u);
}

// First we DFS through the bidirectional graph, and greedily(ish)
// adding all the edges we can that are not already used. 
// So first we connect the parent to the node, then connect only the
// children of the node that are VISITED already! So these will loop
// back to create cycles (for most of them at least, the 'active' ones).
// We will not actually process the ones ahead yet, and leave that
// for DFS to do. 
// Then we run Kosaraju's algorithm to see if everything is one 
// connected component. If it is, we output the result accordingly.

// Note I do have some bfs commented out, it does not work but was
// part of my first iteration of the solution :)o

// Also note plenty of optimizations could have been made, e.g.
// we use Tarjan instead of Kosaraju's algorithm, and instead of
// using a SCC algorithm, we could have just checked for bridges
// as a graph with a bridge will not be able to change its paths
// to become one-directional, as it will 'disconnect' itself along
// this bridge.
void solve() {
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    /*
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int v = q.front();
            q.pop();
            if (!used[v]) {
                used[v] = true;
                for (int u : g[v]) {
                    if (!used[u]) {
                        q.push(u);
                    }
                    if (!adj[u].count(v)) {
                        adj[v].insert(u);
                        rev[u].push_back(v);
                    }
                }
            }
        }
    }
    */
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs0(i, 0);
        }
    }
    vis.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    //cout << endl;

    vis.assign(n+1, false);
    reverse(order.begin(), order.end());
    for (int o : order) {
        if (!vis[o]) {
            dfs2(o);
        }
        break;
    }
    if (comp.size() == n) {
        for (int i = 1; i <= n; i++) {
            for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
                cout << i << " " << *it << '\n';
            }
        }
    } else {
        cout << 0 << '\n';
    }

}

