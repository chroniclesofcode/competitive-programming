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
const LL MOD = 1e9 + 7;

LL n, m;
vector<LL> adj[MX];
vector<LL> rev[MX];
LL dp[MX];
LL in_deg[MX];
LL pred[MX];
/*

*/


void solve() {
    cin >> n >> m;
    LL t1,t2;
    for (LL i = 0; i < m; i++) {
        cin >> t1 >> t2;
        adj[t1-1].push_back(t2-1);
        rev[t2-1].push_back(t1-1);
        in_deg[t2-1]++;
    }

    queue<LL> q;
    for (LL i = 0; i < n; i++) {
        dp[i] = -INF;
        pred[i] = -1;
        if (in_deg[i] == 0) q.push(i);
    }
    dp[0] = 1;
    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0) q.push(v);
        }

        for (auto &p : rev[u]) {
            //cout << "u: " << u+1 << " rev " << p+1 << endl;
            if (dp[p]+1 > dp[u]) {
                dp[u] = dp[p]+1;
                pred[u] = p;
            }
        }
    }


    pred[0] = -1;

    LL p = n-1;
    vector<LL> paths;
    while (p != -1) {
        paths.push_back(p);
        p = pred[p];
    }
    reverse(paths.begin(), paths.end());
    if (paths[0] != 0 || paths[paths.size()-1] != n-1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << paths.size() << endl;
    for (auto &e : paths) {
        cout << e+1 << " ";
    }
    cout << endl;
    
}





