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

int n, m, grp[MX], sz[MX], reach[MX];
bool vis[MX];
vector<int> adj[MX];

int Find(int a) {
    if (grp[a] == a) {
        return a;
    }
    return grp[a] = Find(grp[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        grp[b] = a;
        sz[a] += sz[b];
        reach[a] = max(reach[a], reach[b]);
    }
}

/*

*/

void dfs(int u) {
    if (vis[u]) return;
    reach[grp[u]] = max(reach[grp[u]], u);
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            Union(u, v);
            dfs(v);
        }
    }
    return;
}

void solve() {
    cin >> n >> m;
    int x, y;
    for (int i = 0 ; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        grp[i] = i;
        reach[i] = i;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    unordered_map<int, int> seen;
    seen[grp[0]] = 1;
    int ans = 0;
    int curr = reach[grp[0]];
    /*
    for (int i = 0; i < n; i++) {
        cout << "grp["<<i<<"]: "<<grp[i]<<","<<reach[i]<< '\n';
    }
    */
    for (int i = 1; i < n; i++) {
        if (i <= curr) {
            if (!seen[grp[i]]) {
                ans++;
                seen[grp[i]] = 1;
            }
            curr = max(curr, reach[grp[i]]);
        } else {
            seen[grp[i]] = 1;
            curr = reach[grp[i]];
        }
    }
    cout << ans << '\n';
}





