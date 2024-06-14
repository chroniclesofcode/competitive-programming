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
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

int timer = 1;
int tin[MX], tout[MX], par[MX], LG, diff[MX], ans[MX];
vector<int> adj[MX];
vector<vector<int>> up;


void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    if (p != -1) {
        par[u] = p;
    }
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

int calc(int u, int p) {
    int sm = diff[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        sm += calc(v, u);
    }
    ans[u] = sm;
    return sm;
}

void solve() {
    int paths;
    cin >> n >> paths;
    for (int i = 30; i >= 0; i--) {
        if (n & (1 << i)) {
            LG = i+1;
            break;
        }
    }
    up = vector<vector<int>>(n+1, vector<int>(LG+1, -1));
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for (int p = 0; p < paths; p++) {
        int a, b; cin >> a >> b; a--; b--;
        diff[a]++; diff[b]++;
        int anc = lca(a,b);
        diff[anc]--; // from a and b
        if (anc != 0) diff[par[anc]]--; // from paths
    }
    calc(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
