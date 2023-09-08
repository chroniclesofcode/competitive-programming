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

int timer = 1;
int n, q, tin[MX], tout[MX], dep[MX], LG;
vector<int> adj[MX];
vector<vector<int>> up;

/*

*/
void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    if (p != -1) dep[u] = dep[p]+1;
    for (int i = 1; i <= LG; i++) {
        if (up[u][i-1] != -1)
            up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

// is v one of the childs of u?
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u,v)) return u;
    if (is_ancestor(v,u)) return v;

    for (int i = LG; i >= 0; i--) {
        if (up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int dist(int a, int b) {
    int node = lca(a, b);
    return dep[a]+dep[b]-2*dep[node];
}

void solve() {
    cin >> n >> q;
    for (int i = 30; i >= 0; i--) {
        if (n & (1 << i)) {
            LG = i+1;
            break;
        }
    }
    up = vector<vector<int>>(n+1, vector<int>(LG+1, -1));
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << dist(a, b) << '\n';
    }
}





