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

int n, m, dp[MX][26];
bool vis[MX], active[MX], seen[MX];
string s;
vector<int> order, adj[MX], rev[MX];
/*

*/

bool hasCycle(int u) {
    if (vis[u]) return false;
    vis[u] = true;
    active[u] = true;

    for (int v : adj[u]) {
        if (active[v] || hasCycle(v)) {
            return true;
        }
    }
    active[u] = false;
    return false;
}

void dfs(int u) {
    if (seen[u]) return;
    seen[u] = 1;
    for (int v : adj[u]) {
        if (!seen[v]) dfs(v);
    }
    order.push_back(u);
    return;
}

void solve() {
    cin >> n >> m;
    cin >> s;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && hasCycle(i)) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }
    int ans = 0;
    reverse(order.begin(), order.end());
    for (int u : order) {
        int ch = s[u] - 'a';
        for (int v : rev[u]) {
            for (int i = 0; i < 26; i++) {
                dp[u][i] = max(dp[u][i], dp[v][i]);
            }
        }
        dp[u][ch]++;
        ans = max(ans, dp[u][ch]);
        /*
        cout << "\nafter " << u+1 << ':' << "\n";
        for (int i = 0; i < 26; i++) {
            cout << (char)(i + 'a') << ": " << dp[u][i] << ' ';
        }
        */
    }
    cout << ans << '\n';
}





