#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, a, b;
int cycle = -1;
vector<int> adj[MX];
int vis[MX];

void dfs(int u, int prev) {
    if (cycle != -1) return;
    if (vis[u]) {
        cycle = u;
        return;
    }
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v != prev) dfs(v, u);
    }
}

int bfs(int start, int target) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(start);
    int lv = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
             int u = q.front();
            q.pop();
            if (vis[u]) continue;
            if (u == target) {
                return lv;
            }
            vis[u] = 1;
            for (auto v : adj[u]) {
                if (!vis[v]) q.push(v);
            }
        }
        lv++;
    }
    return -1;
}

void solve() {
    // a is chaser, b is runner
    cin >> n >> a >> b;
    a--; b--;
    cycle = -1;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(b, b);
    int run = bfs(b, cycle);
    int chase = bfs(a, cycle);
    if (run < chase) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    //cout << "run: " << run << " chase: " << chase << '\n';
    //cout << "cycle: " << cycle << '\n';
}

/*
    DFS from the starting element and find the point where
   it enters the only cycle in the graph. Use dfs from chaser.
   Then dijkstra from the chaser. See if it reaches this
   point first or the other person.
*/







