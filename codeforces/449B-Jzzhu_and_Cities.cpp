#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

        solve();
}
#define INF numeric_limits<LL>::max()
const LL MX = 3 * 1e5 + 100;

struct Edge {
    LL u, v, w;

    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

vector<Edge> adj[MX];
LL routes[MX];
bool used[MX];
LL dist[MX];
vector<pair<LL, LL>> trains;


class Compare
{
public:
    bool operator() (Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

priority_queue<Edge, vector<Edge>, Compare> pq;

/*
    Count shortest path routes to each node using modified
    dijkstra. Then iterate through all train routes, if 
    routes for that node > 1, then don't take that train route.
    Then route--. If it happens so there's only 1 route left
    for that specific node, then we take that train.

    Then subtract from k to get your final answer: the ones you
    don't need.

*/

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    for (LL i = 0; i < m ;i++) {
        LL u, v, x;
        cin >> u >> v >> x;
        // note: the WEIGHT is FIRST!
        adj[u].push_back({ u, v, x });
        adj[v].push_back({ v, u, x });
    }
    for (LL i = 0; i < k; i++) {
        LL s, y;
        cin >> s >> y;
        adj[1].push_back({ 1, s, y });
        //adj[s].push_back({ s, 1, y });
        trains.push_back(make_pair(y, s));

    }
    routes[0] = 1;
    pq.push({ 0, 1, 0 });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        LL v = cur.v;
        LL d = cur.w;
        if (used[v]) {
            if (dist[v] == d) {
                routes[v] += routes[cur.u];
            }
            continue;
        }
        dist[v] = d;
        used[v] = true;
        routes[v] += routes[cur.u];

        for (auto nxt : adj[v]) {
            LL u = nxt.v;
            LL d2 = nxt.w;
            //d2 = d2 < 0 ? -d2 : d2;
            //if (!used[u]) {
                pq.push({ v, u, d+d2 });
            //}
        }
    }
    LL ret = 0;

    for (auto cur : trains) {
        LL w = cur.first;
        LL v = cur.second;
        if (dist[v] == w && routes[v] == 1) {
            ret++;
        } else if (dist[v] == w && routes[v] > 1) {
            routes[v]--;
        }
    }

    cout << k - ret << '\n';
    /*
    for (auto cur : trains) {
        LL w = cur.first;
        LL v = cur.second;
        if (dist[v] < w) {
            //cout << "CLOSE: " << v << " WEIGHT: " << w << endl;
            ret++;
        } else if (dist[v] == w) {
            //cout << "ran for " << v << " routes: " << routes[v] << endl;
            if (routes[v] > 1) {
                //cout << "CLOSE: " << v << " WEIGHT: " << w << endl;
                //cout << "Note: routes is " << routes[v] << endl;
                ret++;
                routes[v]--;
            } 
        }
    }

    cout << ret << '\n';
    */
}


