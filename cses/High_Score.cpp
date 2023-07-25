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

#define INF numeric_limits<LL>::max()/2
#define NINF -INF
const LL MX = 3000;
//const LL MOD = 1e7;

LL n, m;

LL ans = 0;
/*
    Add in all nodes as the negative equivalent, 
    then run bellman ford to find the shortest path
    but this actually will be the LONGEST path.
    We then run bellman ford again, checking all edges
    which can still be relaxed N times, this will propagate
    all negative cycles throughout the dist array

    It should be clear if the final answer is part of
    the negative cycle, then there is an infinite high
    score. This approach is needed because we are actually
    looking for real cycles - and we should ignore the
    real negative cycles, since they take away from
    score instead of give.
*/

vector<array<LL, 2>> adj[MX];
bool vis[MX];
vector<LL> dist(MX, INF);

void solve() {
    cin >> n >> m;
    LL a, b, x;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> x;
        adj[a-1].push_back({ b-1, -x });
    }   
    dist[0] = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if (dist[j] == INF) continue;
            for (auto &k : adj[j]) {
                // going to be from j -> k
                // 0 is dest, 1 is weight
                if (dist[j] + k[1] < dist[k[0]]) {
                    dist[k[0]] = dist[j] + k[1];
                }
            }
        }
    }
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if (dist[j] == INF) continue;
            for (auto &k : adj[j]) {
                // going to be from j -> k
                // 0 is dest, 1 is weight
                if (dist[j] + k[1] < dist[k[0]]) {
                    dist[k[0]] = NINF;
                }
            }
        }
    }
    if (dist[n-1] == NINF) {
        cout << -1 << endl;
        return;
    }
    cout << dist[n-1] * -1 << endl;
}





