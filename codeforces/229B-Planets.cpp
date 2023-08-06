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
#define arr array<LL,2>

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, m;
vector<arr> adj[MX];
vector<LL> t[MX];
vector<LL> skip[MX];
bool vis[MX];
LL dist[MX];

/*

*/

void solve() {
    cin >> n >> m;
    LL x, y, z;
    for (LL i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    for (LL i = 0; i < n; i++) {
        cin >> x;
        for (LL j = 0; j < x; j++) {
            cin >> y;
            t[i].push_back(y);
        }
        if (x > 0) {
            LL last = t[i][x-1]+1;
            skip[i].push_back(last);
            for (LL j = x-2; j >= 0; j--) {
                if (t[i][j] == t[i][j+1]-1) {
                    skip[i].push_back(last);
                } else {
                    last = t[i][j]+1;
                    skip[i].push_back(last);
                }
            }
            reverse(skip[i].begin(), skip[i].end());
        }
    }
    for (LL i = 0; i < n; i++) {
        dist[i] = INF;
    }
    priority_queue<arr, vector<arr>, std::greater<arr>> pq;
    pq.push({ 0, 0 });
    //dist[0] = 0;
    while (!pq.empty()) {
        arr fr = pq.top();
        pq.pop();
        LL u = fr[1];
        LL w = fr[0];
        //cout << "visited u: " << u+1 << " dist: " << w << '\n';
        //vis[u] = true;
        //dist[u] = min(dist[u], w);
        auto it = lower_bound(t[u].begin(), t[u].end(), w);
        LL ct = 0;
        if (u != n-1 && it != t[u].end() && *it == w) {
            int idx = it - t[u].begin();
            ct = skip[u][idx] - *it;
        }
        //dist[u] = min(dist[u], w+ct);
        if (dist[u] > w+ct) {
            dist[u] = w+ct;
        } else {
            continue;
        }
        //cout << "modified to " << dist[u] << " ct: " << ct << '\n';
        for (auto &[v, d] : adj[u]) {
            if (dist[v] > dist[u] + d) {
                //dist[v] = dist[u] + d;
                pq.push({dist[u]+d, v});
            }
        }
    }
    cout << (dist[n-1] == INF ? -1 : dist[n-1]) << '\n';
}





