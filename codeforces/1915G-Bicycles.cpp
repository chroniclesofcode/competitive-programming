#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<LL,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1001;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
vector<arr> adj[MX];
LL bikes[MX], dist[MX], vis[MX];

void solve() {
    // input
    cin >> n >> m;
     // reset
    memset(bikes, 0, sizeof(bikes));
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    for (LL i = 0; i < n; i++) {
        adj[i].clear();
        dist[i] = INF;
    }
   
    for (LL i = 0; i < m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (LL i = 0; i < n; i++) {
        LL s;
        cin >> s;
        bikes[i] = s;
    }

    // time, speed, node
    using tmp = array<LL,3>;
    priority_queue<tmp, vector<tmp>, greater<tmp>> pq;
    pq.push({0, bikes[0], 0});
    while (!pq.empty()) {
        auto tp = pq.top();
        LL time = tp[0], speed = tp[1], u = tp[2];
        pq.pop();
        if (vis[u] != 0 && speed >= vis[u]) {
            continue;
        }
        vis[u] = min(speed, bikes[u]);
        dist[u] = min(dist[u], time);
        for (auto [v, len] : adj[u]) {
            //pq.push({time+len*speed, speed, v});
            //pq.push({time+len*bikes[u], bikes[u], v});
            pq.push({time+len*vis[u], vis[u], v});
        }
    }
    cout << dist[n-1] << '\n';
}

/*
   2D visited array, 2D distances for each bike
   run a single huge dijkstra, getting the 
   distances to every node.
   In our PQ, prioritise the slowness factor of
   a bike. So if a faster bike arrives at a city
   later, allow it to do so. However, if a bike
   that is not the fastest arrive, forbid it.

   OR

   dijkstra from each city -> so you know how long
   it takes to reach every other city using a
   certain bike

   5*2 + 2*1 + 1 + 5 + 1
*/







