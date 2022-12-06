#include <bits/stdc++.h>
#include <fstream>

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
const LL MX = 5 * 1e6 ;
//const LL MOD = 1e9 + 7;
const LL ADD = 100001;

LL n, s, f, m, g;
LL dp[MX];
vector<int> god[MX];
vector<pair<int, int>> adj[MX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
int dist[MX];
bool seen[MX];

void solve() {
    cin >> n >> s >> f >> m >> g;
    s--; f--;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int w;
            cin >> w;
            w--;
            god[w].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    for (int i = 0; i < g; i++) {
        int p;
        cin >> p;
        int sz = god[i].size();
        for (int j = 0; j < sz; j++) {
            adj[god[i][j]].push_back({i+ADD, p});
            adj[i+ADD].push_back({god[i][j], 0});
        }
    }

    pq.push({0, s}); // distance to s itself is zero
    while (!pq.empty()) {
        // choose (d, v) so that d is minimal
        // i.e. the closest unvisited vertex
        auto cur = pq.top();
        pq.pop();
        int v = cur.second , d = cur.first;
        if (seen[v]) continue;
        dist[v] = d;
        seen[v] = true;
        // relax all edges from v
        for (auto nxt : adj[v]) {
            int u = nxt.first , weight = nxt.second;
            if (!seen[u])
                pq.push({d + weight , u});
        }
    }
    if (dist[f] == 0) {
        cout << "-1\n";
        return;
    }
    cout << dist[f] << '\n';
}





