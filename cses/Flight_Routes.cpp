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

const LL MX = 1e5 + 10;
//const LL MOD = 1e7;

LL n, m, k;

/*

*/

priority_queue<array<LL,2>, vector<array<LL,2>>, greater<array<LL,2>>> pq;

priority_queue<LL> best[MX];

vector<array<LL,2>> adj[MX];

//LL dist[MX];
//bool vis[MX];
LL paths[MX];

void solve() {
    cin >> n >> m >> k;
    LL a, b, c;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // from, { weight, to }
        adj[a-1].push_back({ c, b-1 });
    }
   
    best[0].push(0);
    // dist, node, numpaths to node
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        auto top = pq.top();
        LL weight = top[0];
        LL v = top[1];
        pq.pop();
        //cout << "v: " << v+1 <<  " w: " << top[0] <<  endl;
        if (best[v].size() == k && weight > best[v].top()) continue;

        // from: v, to: u
        LL w, u;
        for (auto &e : adj[v]) {
            w = e[0];
            u = e[1];

            if (best[u].size() < k) {
                best[u].push(w + weight);
                pq.push({ w + weight, u });
            } else if (best[u].size() == k && best[u].top() > w + weight) {
                best[u].pop();
                best[u].push(w + weight);
                pq.push({ w + weight, u });
            }
        }
    }
    vector<LL> ans;
    for (LL i = 0; i < k; i++) {
        ans.push_back(best[n-1].top());
        best[n-1].pop();
    }
    reverse(ans.begin(), ans.end());
    for (LL i = 0; i < k; i++) cout << ans[i] << " ";
    cout << endl;

}





