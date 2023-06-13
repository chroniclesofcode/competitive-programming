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
//const LL MOD = 1e7;

int n, m;
vector<int> adj[MX];
stack<int> s;
bool vis[MX];
bool v2[MX];
int flag = 0;
/*
   simple top sort
*/

void dfs(int u) {
    if (v2[u]) {
        flag = 1;
        return;
    }
    if (vis[u] || flag) {
        return;
    }
    vis[u] = true;
    v2[u] = true;

    for (auto &v : adj[u]) {
        dfs(v);
    }

    v2[u] = false;

    s.push(u);
}

void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    for (int i = 0; i < n; i++) {
        if (flag) break;
        dfs(i);
    }
    if (flag) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    while (!s.empty()) {
        cout << s.top()+1 << " ";
        s.pop();
    }
    cout << endl;
}





