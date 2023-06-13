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

LL n, m;
vector<LL> adj[MX];
LL pred[MX];
bool vis[MX];
bool vis2[MX];
int flag = 0;
int endv = -1;
/*

*/

void dfs(LL v, LL p) {
    //cout << "v: " << v+1 << " " << p+1 << " " << vis2[v] << endl;
    if (flag) {
        return;
    }
    if (vis2[v]) {
        flag = 1;
        pred[v] = p;
        endv = v;
        return;
    }
    if (vis[v]) return;
    vis[v] = true;
    vis2[v] = true;
    pred[v] = p;

    for (auto &u : adj[v]) {
        dfs(u, v);
    }
    vis2[v] = false;
}

void solve() {
    cin >> n >> m;
    LL z1, z2;
    for (LL i = 0; i < m; i++) {
        cin >> z1 >> z2;
        adj[z1-1].push_back(z2-1);
    }
    for (int i = 0; i < n; i++) {
        if (flag) break;
        dfs(i, -1);
    }

    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<LL> path;
    for (LL p = pred[endv]; p != endv; p = pred[p]) {
        path.push_back(p);
    }
    if (path.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(path.begin(), path.end());
    cout << path.size()+2 << endl;
    cout << endv+1 << " ";
    for (auto &e : path) {
        cout << e+1 << " ";
    }
    cout << endv+1 << endl;
    
}





