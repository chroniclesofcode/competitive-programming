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
/*
   dp represents longest dist to each node
   0 or 1 depending from left or right of diameter
*/
int dp[MX][2];
int mxval = 0;
int mxidx = 0;

void dfs(int u, int p, int dep, int idx) {
    dp[u][idx] = dep;
    if (dep > mxval) {
        mxval = dep;
        mxidx = u;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, dep+1, idx);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0, 0, 0);
    int a = mxidx; // furthest from 0
    mxval = 0;
    dfs(a, -1, 0, 0);
    int b = mxidx; // furthest from a
    dfs(b, -1, 0, 1);
    
    for (int i = 0; i < n; i++) {
        cout << max(dp[i][0],dp[i][1]) << ' ';
    }
    cout << '\n';
}





