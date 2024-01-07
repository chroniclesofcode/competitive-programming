#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 1 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
vector<int> ans;
vector<array<int,2>> adj[MX];
int vis[MX];

bool dfs(int u, int p, bool problem) {
    bool flag = false;
    for (auto e : adj[u]) {
        int v = e[0], t = e[1];
        if (v == p) continue;
        flag |= dfs(v, u, t);
    }
    if (!flag && problem) {
        ans.push_back(u);
        return true;
    }
    return flag;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x,y,t; cin >> x >> y >> t;
        x--; y--;
        adj[x].push_back({y,t==2});
        adj[y].push_back({x,t==2});
    }
    dfs(0, -1, false);
    cout << ans.size() << '\n';
    for (auto a : ans) {
        cout << a+1 << ' ';
    }
    cout << '\n';
}

/*

*/



