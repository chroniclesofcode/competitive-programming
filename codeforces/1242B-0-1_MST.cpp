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
const LL MX = 2 * 1e5;
//const LL MOD = 1e7;

int n, m;
set<int> adj[MX], uns;
/*

*/

void dfs(int u) {
    uns.erase(u);
    vector<int> rem;
    for (auto it = uns.begin(); it != uns.end(); it = uns.upper_bound(*it)) {
        if (!adj[u].count(*it)) {
            rem.push_back(*it);
        }
    }
    for (auto v : rem) {
        uns.erase(v);
    }
    for (auto v : rem) {
        dfs(v);
    }
}

void solve() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for (int i = 0; i < n; i++) {
        uns.insert(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (uns.count(i)) {
            dfs(i);
            ans++;
        }
    }

    cout << ans-1 << '\n';
}





