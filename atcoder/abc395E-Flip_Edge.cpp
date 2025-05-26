#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

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

int n, m, k, q, x;

vector<arr2> adj[MX];

void solve() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1}); // 1 means reversed
    }
    vector<vector<LL>> vis(2, vector<LL>(n+1, 0));
    vector<vector<LL>> dist(2, vector<LL>(n+1, LINF));
    priority_queue<arr3, vector<arr3>, greater<arr3>> pq;
    pq.push({0, 0, 0}); // dist, node, is_rev?
    while (!pq.empty()) {
        auto tp = pq.top();
        auto &[d, u, is_rev] = tp;
        pq.pop();
        if (vis[is_rev][u]) continue;
        vis[is_rev][u] = 1;
        dist[is_rev][u] = d;
        for (auto &[v, r] : adj[u]) {
            LL cost = (is_rev == r) ? 0 : x;
            if (dist[r][v] > d + 1 + cost) {
                pq.push({d+1+cost, v, r});
            }
        }
    }
    cout << min(dist[0][n-1], dist[1][n-1]) << '\n';
}

/*

*/