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

int timer = 1;
int n, q, tin[MX], tout[MX], LG;
vector<int> adj[MX];
vector<vector<int>> up;

/*

*/
void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= LG; i++) {
        if (up[u][i-1] != -1)
            up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

void solve() {
    cin >> n >> q;
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            LG = i+1;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x; x--;
        adj[x].push_back(i);
    }
    up = vector<vector<int>>(n+1, vector<int>(LG+1, -1));
    dfs(0, -1);
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        int u = x-1;
        for (int j = 0; j <= LG; j++) {
            if (k & (1 << j) && u != -1) {
                u = up[u][j];
            }
        }
        cout << (u == -1 ? -1 : u+1) << '\n';
    }
}





