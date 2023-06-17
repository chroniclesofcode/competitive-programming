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
const LL MOD = 1e9 + 7;

LL n, m;
#define arr array<LL,3>
priority_queue<arr, vector<arr>, greater<arr>> pq;
LL dist[MX];
LL paths[MX];
bool vis[MX];
vector<arr> adj[MX];
LL minf[MX];
LL maxf[MX];
/*

*/

void solve() {
    LL a, b, c;
    cin >> n >> m;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({ c, b-1 });
    }
    for (LL i = 0; i < n; i++) {
        dist[i] = INF;
        //minf[i] = INF;
        //maxf[i] = NINF;
    }
    paths[0] = 1;
    dist[0] = 0;
    pq.push({0,0});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        LL u = top[1];
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &v : adj[u]) {
            if (dist[v[1]] > dist[u] + v[0]) {
                minf[v[1]] = minf[u]+1;
                maxf[v[1]] = maxf[u]+1;
                dist[v[1]] = dist[u] + v[0];
                paths[v[1]] = paths[u];
                pq.push({dist[v[1]], v[1]});
            } else if (dist[v[1]] == dist[u] + v[0]) {
                minf[v[1]] = min(minf[v[1]], minf[u]+1);
                maxf[v[1]] = max(maxf[v[1]], maxf[u]+1);
                paths[v[1]] += paths[u];
                paths[v[1]] %= MOD;
                pq.push({dist[v[1]], v[1]});
            }
        }
    }

    cout << dist[n-1] << " " << paths[n-1] << " " << minf[n-1] << " " << maxf[n-1] << endl;
}





