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
vector<int> ans, adj[MX];
/*

*/

void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        deg[a]++;
        deg[b]++;
        in[b]++;
        out[a]++;
    }

    bool flag = 0;
    if (deg[0] % 2 != 1 || deg[n-1] % 2 != 1) {
        flag = 1;
    }
    for (int i = 1; i < n-1; i++) {
        if (deg[i] % 2 == 1) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    s.push(0);
    vector<int> ans;
    while (!s.empty()) {
        int u = s.top();
        if (out[u] == 0) {
            s.pop();
            ans.push_back(u);
        } else {
            int v = adj[u].back();
            s.push(v);
            adj[u].pop_back();
            in[v]--;
            out[u]--;
        }
    }
    if (ans.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    for (auto &u : ans) cout << u+1 << " ";
    cout << endl;

}



