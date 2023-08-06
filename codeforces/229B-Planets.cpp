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
   Modified dijkstra, every time we arrive and there's a 
   time clash, we wait. I was getting TLE, but the solution
   was to find the intervals to the end-waiting time, instead
   of manually iterating through the array (basically I just got
   lazy...)
   Otherwise fairly simple, don't use a visited array, just only
   push when you relax the edge properly.
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
            // Creating the skip array, it will correspond
            // to t[i][j] to the time you need to skip to.
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
    while (!pq.empty()) {
        arr fr = pq.top();
        pq.pop();
        LL u = fr[1];
        LL w = fr[0];
        auto it = lower_bound(t[u].begin(), t[u].end(), w);
        LL ct = 0;
        // Processing the interval, calculating the index.
        // Probably didn't NEED to do it, but it fit in
        // with my old refactored implementation
        if (u != n-1 && it != t[u].end() && *it == w) {
            int idx = it - t[u].begin();
            ct = skip[u][idx] - *it;
        }
        if (dist[u] > w+ct) {
            dist[u] = w+ct;
        } else {
            continue;
        }
        for (auto &[v, d] : adj[u]) {
            // No visited array, just push when relaxing
            if (dist[v] > dist[u] + d) {
                pq.push({dist[u]+d, v});
            }
        }
    }
    cout << (dist[n-1] == INF ? -1 : dist[n-1]) << '\n';
}





