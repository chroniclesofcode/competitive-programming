#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2027;
constexpr int MD = 998244353;

int n, m, grp[MX];
vector<int> adj[MX], rev[MX], scc[MX], rscc[MX];
vector<vector<LL>> dp;
vector<bool> vis(MX, false);
vector<int> order, comp, rts;

void calc(int u, int p) {
    for (auto v : scc[u]) {
        if (v != p) {
            calc(v, u);
            long long tot = 0;
            for (int i = 0; i < m; i++) {
                tot = (tot + dp[v][i]) % MD;
                dp[u][i] = (dp[u][i] * tot) % MD;
            }
        }
    }
}

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
    vector<int> A(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a--;
        if (a != i) {
            adj[a].push_back(i);
            rev[i].push_back(a);
        }
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
                rscc[r2].push_back(r1);
            }
        }
    }

    // calculations after kosaraju (where the algo begins)
    vis.assign(n, false);
    long long ans = 1; 
    dp = vector<vector<long long>>(n, vector<long long>(m, 1));
    for (int i = 0; i < n; i++) {
        int r1 = grp[i];
        if (!vis[r1] && rscc[i].size() == 0) {
            vis[r1] = true;
            calc(r1, -1);
            LL cs = 0;
            for (int j = 0; j < m; j++) {
                cs = (cs + dp[r1][j]) % MD;
            }
            ans = (ans * cs) % MD;
        }
    }
    
    cout << ans << '\n';
}
/*
break into SCC. All cycles must take the same value, so treat as one.
we traverse downwards, recursively, calculating the values via BFS.
Each vertex we can use dp, for each node i, if it takes value j,
how many ways can we 
For each root, we will do the recursion, and multiply all the roots
together at the very end for the final ans.
*/