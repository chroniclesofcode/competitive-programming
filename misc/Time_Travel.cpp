#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    //std::cin.tie(nullptr);
    //std::cin.sync_with_stdio(false);
        solve();
}
#define INF numeric_limits<LL>::max() / 2
//const LL MX = 1500;
typedef pair <LL, LL> edge; 
const LL N = 100100;
LL n, m;
vector <edge > edges[N];
LL dist[N];
bool seen[N];
priority_queue <edge , vector <edge >, greater <edge >> pq;
LL start[N];
LL finish[N];

void dijkstra (LL s) {
    pq.push(edge(0, s)); 
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        LL v = cur.second , d = cur.first;
        //cout << "edge to: " << v << " with dist: " << d << endl;
        if (d < dist[v]) {
            dist[v] = d;
            seen[v] = true;
            // relax all edges from v
            for (edge nxt : edges[v]) {
                LL u = nxt.second , weight = nxt.first;
                LL res = d + weight;
                if (start[u] != -1 && res < start[u]) {
                    res = start[u];
                } else if (finish[u] != -1 && res > finish[u]) {
                    res = finish[u];
                }
                pq.push(edge(res , u));
            }
        }
        if (seen[v]) continue;
        //dist[v] = d;
        seen[v] = true;
        // relax all edges from v
        for (edge nxt : edges[v]) {
            LL u = nxt.second , weight = nxt.first;
            LL res = d + weight;
            if (start[u] != -1 && res < start[u]) {
                res = start[u];
            } else if (finish[u] != -1 && res > finish[u]) {
                res = finish[u];
            }
            pq.push(edge(res , u));
        }
    }
}

void solve() {
    cin >> n >> m;
    for (LL i = 0; i < n; i++) {
        LL s, f;
        cin >> s >> f;
        start[i] = s;
        finish[i] = f;
    }

    for (LL i = 0; i < m; i++) {
        LL a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        edges[a].push_back({t, b});
        edges[b].push_back({t, a});
    }

    for (LL i = 0; i < n+1; i++) {
        dist[i] = INF;
    }

    dijkstra(0);
    cout << dist[n-1] << '\n';
}





