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

const LL MX = 2 * 1e5;
//const LL MOD = 1e7;

int n, m, in[MX], out[MX], deg[MX];
stack<int> s;
vector<int> ans;
multiset<int> adj[MX];
/*

*/

void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] % 2 == 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    s.push(0);
    while (!s.empty()) {
        int u = s.top();
        if (deg[u] == 0) {
            s.pop();
            ans.push_back(u);
        } else {
            int v = *(adj[u].begin());
            s.push(v);
            adj[u].erase(adj[u].find(v));
            adj[v].erase(adj[v].find(u));
            deg[u]--;
            deg[v]--;
        }
    }
    if (ans.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    for (auto &e : ans) cout << e+1 << " ";
    cout << endl;
}





