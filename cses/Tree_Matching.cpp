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

int n;
vector<int> adj[MX];
int ans = 0;
bool vis[MX];

/*

*/

void dfs(int u, int prev) {
    for (int v : adj[u]) {
        if (v != prev) {
            dfs(v, u);
        }
    }
    if (prev != 0 && !vis[u] && !vis[prev]) {
        vis[u] = 1; vis[prev] = 1;
        ans++;
    }
}

void solve() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
}





