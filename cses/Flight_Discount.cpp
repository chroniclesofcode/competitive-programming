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

#define INF (numeric_limits<LL>::max()/5) * 4
#define NINF -INF
const LL MX = 1e6;
//const LL MOD = 1e7;

LL n, m;

LL ans = 0;
/*

*/

LL dist[MX][2];
bool vis[MX][2];
priority_queue<array<LL,3>, vector<array<LL,3>>, greater<array<LL,3>>> pq;
vector<array<LL,2>> adj[MX];

void solve() {
    cin >> n >> m;
    LL a, b, c;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({c, b-1});
    }
    for (LL i = 0; i < n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    dist[0][0] = dist[0][1] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto top = pq.top();
        LL v = top[2];
        LL used = top[1]; // 1 if used
        pq.pop();
        //cout << "visited: " << v << " used: " << used << " w: " << top[0] << endl;
        if (vis[v][used]) continue;
        vis[v][used] = 1;
        for (auto &e : adj[v]) {
            if (dist[e[1]][used] > dist[v][used] + e[0]) {
                dist[e[1]][used] = dist[v][used] + e[0];
            }
            if (used) {
                pq.push({dist[e[1]][1],1, e[1]});
            } else {
                if (dist[e[1]][1] > dist[v][0] + e[0]/2) {
                     dist[e[1]][1] = dist[v][0] + e[0]/2;
                     pq.push({dist[e[1]][1]/2,1, e[1]});
                }
                pq.push({dist[e[1]][0], 0, e[1]});
            }
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << (dist[i][0] == INF ? -1 : dist[i][0]) << " ";
    }
    */
    cout << dist[n-1][1] << endl;
}





