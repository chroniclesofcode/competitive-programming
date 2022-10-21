#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5100;
vector<pair<int, int>> adj[MX];
int colors = 1;
bool used[MX];
bool active[MX];
int col[MX];

void dfs1(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    active[v] = true;
    for (pair<int, int> &p : adj[v]) {
        int u = p.first;
        int num = p.second;
        if (active[u]) {
            colors = 2;
            col[num] = 2;
        } else {
            col[num] = 1;
            dfs1(u);
        }
    }
    active[v] = false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(make_pair(v, i));
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    cout << colors << '\n';
    for (int i = 1; i <= m; i++) {
        cout << col[i] << " ";
    }
    cout << '\n';
}

