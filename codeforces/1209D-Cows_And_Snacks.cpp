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
//const LL MOD = 1e7;

int n, k, sz[MX], grp[MX], vis[MX];
vector<int> adj[MX];

int Find(int a) {
    if (a == grp[a]) return a;
    return grp[a] = Find(grp[a]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        grp[b] = a;
        sz[a] += sz[b];
    }
}

/*

*/

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            Union(u, v);
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> k;
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        grp[i] = i;
        sz[i] = 1;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans += sz[Find(i)] - 1;
        }
    }
    cout << k - ans << '\n';
}





