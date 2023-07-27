#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

#define arr array<int,3>
int n, m, vis[MX], seen[MX],in[MX], active[MX], pos[MX];
vector<int> adj[MX];
vector<int> order;
vector<arr> edges;
/*
   Very simple, I did end up peeking at editorial because
   I was doubting my algorithm on a testcase when it actually works
   and I thought there was a cycle when there really wasn't.

   Basically, construct the graph with no undirected edges,
   run topsort and basically direct each edge left->right in
   topsort order. Very simple.
*/

void dfs(int u) {
    if (vis[u]) {
        return;
    }
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v);
    }
    order.push_back(u);
}

bool hasCycle(int u) {
    if (active[u]) return true;
    if (seen[u]) return false;
    seen[u] = 1;
    active[u] = 1;
    for (int v : adj[u]) {
        if (active[v] || hasCycle(v)) {
            return true;
        }
    }
    active[u] = 0;
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        vis[i] = 0;
        active[i] = 0;
        seen[i] = 0;
        in[i] = 0;
    }
    order.clear();
    edges.clear();
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> z >> x >> y;
        x--; y--;
        if (z) {
            adj[x].push_back(y);
            in[y]++;
        } 
        edges.push_back({z,x,y});
    }
    for (int i = 0; i < n; i++) {
        if (!seen[i] && hasCycle(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    int ct = 0;
    for (int i = 0; i < order.size(); i++) {
        pos[order[i]] = ct++;
    }
    for (auto e : edges) {
        //cout << e[0] << ' ';
        if (!e[0] && pos[e[1]] > pos[e[2]]) {
            swap(e[1], e[2]);
        }
        cout << e[1]+1 << ' ' << e[2]+1 << '\n';
    }
}





