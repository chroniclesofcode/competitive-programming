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

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, m, k, a[MX], dist[MX], revdist[MX];
vector<LL> adj[MX];
bool vis[MX];
bool revvis[MX];
/*

*/

void debug() {
    cout << "DIST\n";
    for (LL i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << "\nREVDIST\n";
    for (LL i = 0; i < n; i++) {
        cout << revdist[i] << ' ';
    }
    cout << endl;
}   
void solve() {
    cin >> n >> m >> k;
    for (LL i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    LL x, y;
    for (LL i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (LL i = 0; i < n; i++) {
        dist[i] = INF;
        revdist[i] = INF;
    }
    #define arr array<LL,2>
    queue<arr> q;
    q.push({0,0});
    while (!q.empty()) {
        arr e = q.front();
        LL w = e[0];
        LL u = e[1];
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        dist[u] = min(dist[u], w);
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push({w+1,v});
            }
        }
    }
    q.push({0,n-1});
    while (!q.empty()) {
        arr e = q.front();
        LL w = e[0];
        LL u = e[1];
        q.pop();
        if (revvis[u]) continue;
        revvis[u] = 1;
        revdist[u] = min(revdist[u], w);
        for (auto v : adj[u]) {
            if (!revvis[v]) {
                q.push({w+1,v});
            }
        }
    }
    // sort it based on the difference between 1->k and k->n
    // aka how even the lengths are
    // because if it's uneven, the shorter side to the other side
    // will always be taken. So we have to minimize that.
    #define arr array<LL,2>
    vector<arr> lens;
    for (LL i = 0; i < k; i++) {
        lens.push_back({dist[a[i]]-revdist[a[i]], a[i]});
    }
    // sort so that revdist is longer as we go through
    sort(lens.begin(), lens.end());
    LL ans = 0;
    LL curr = NINF;
    // answer will always be revdist + longest short bit
    for (auto l : lens) {
        LL special = l[1];
        ans = max(ans, revdist[special]+curr);
        curr = max(curr, dist[special]);
    }
    //debug();
    cout << min(dist[n-1], ans+1) << '\n';
}





