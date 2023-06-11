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
const LL MX = 3000;
//const LL MOD = 1e7;

LL n, m;

LL p[MX];

/*

*/

vector<array<LL,2>> adj[MX];
LL dist[MX];

void solve() {
    cin >> n >> m;

    LL a, b, c;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({c, b-1});
    }
    // Bellman ford negative cycle finding
    // Note: n is a super node, it is connected
    // to every single node with a weight of 0
    // to detect isolated islands within graphs.

    // - Note: no new cycles will be created.
    for (LL i = 0; i < n; i++) {
        adj[n].push_back({ 0, i });
        dist[i] = INF;
        p[i] = -1;
    }
    dist[n] = 0;
    LL x = -1;
    for (LL ct = 0; ct < n+2; ct++) {
        x = -1;
        for (LL i = 0; i <= n; i++) {
            if (dist[i] == INF) continue;
            for (auto &j : adj[i]) {
                if (dist[j[1]] > dist[i] + j[0]) {
                    dist[j[1]] = dist[i] + j[0];
                    p[j[1]] = i;
                    x = j[1];
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (LL i = 0; i < n; i++) {
        x = p[x];
    }
    vector<LL> path;
    for (LL c = x;; c = p[c]) {
        path.push_back(c);
        if (c == x && path.size() > 1) {
            break;
        }
    }
    reverse(path.begin(), path.end());
    for  (auto &u : path) {
        cout << u+1 << " ";
    }
    cout << endl;
}





