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
#define INF numeric_limits<LL>::max() / 2
const LL MX = 1100;

struct ErEdge {
    LL u, v, w;
};
// Weight, to, isErased (0 or 1), parent
struct Edge {
    LL first, second, third, par, idx, link;
};

class CMP {
    public:
    bool operator() (Edge a, Edge b) {
        return a.first > b.first;
    }
};

struct PrLLs {
    LL u, v, idx;
};

vector<Edge> adj[MX];
vector<ErEdge> erased;
vector<LL> d(MX);
vector<bool> used(MX);
priority_queue<Edge, vector<Edge>, CMP> pq;
pair<LL, LL> pred[MX]; //parent, modifiable
LL indie[MX];
vector<PrLLs> prLLs;


LL n, m, L, s, t;

LL dijk(void) {
    used.assign(n+1, false);
    d.assign(n+1, INF);

    pq.push({0, s, 0, -1, -1});
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        LL v = cur.second, dist = cur.first;
        if (used[v]) continue;
        d[v] = dist;
        used[v] = true;
        for (LL i = 0; i < adj[v].size(); i++) {
            Edge nxt = adj[v][i];
            LL u = nxt.second, weight = nxt.first;
            if (!used[u]) {
                pq.push({dist + weight, u, 0, v, i});
            }
        }
    }

    return d[t];
}

LL pathtrack(void) {
    used.assign(n+1, false);
    d.assign(n+1, INF);

    pq.push({0, s, 0, -1, -1});
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        LL v = cur.second, dist = cur.first;
        if (used[v]) continue;
        d[v] = dist;
        used[v] = true;
        pred[v] = make_pair(cur.par, cur.third);
        indie[v] = cur.idx;
        for (LL i = 0; i < adj[v].size(); i++) {
            Edge nxt = adj[v][i];
            LL u = nxt.second, weight = nxt.first;
            if (!used[u]) {
                pq.push({dist + weight, u, nxt.third, v, i});
            }
        }
    }

    return d[t];
}

void prLLans() {
    for (auto p : prLLs) {
        cout << p.u << " " << p.v << " " << adj[p.u][p.idx].first << endl;
    }
}

bool modify(LL u, LL sum, LL par) {
    //cout << "u: " << u << " par: " << par << endl;
    pair<LL, LL> &e = pred[u];
    LL v = e.first;
    LL isMod = e.second;
    //cout << "v: " << v << " isMod: " << isMod << endl;
    

    if (isMod) {
        // add to edge the difference
        LL diff = L - sum;
        if (diff < 0) return false;
        //cout << diff << " " << v << " " << indie[par] << " " << adj[v][indie[par]].second << endl;
        adj[v][indie[par]].first += diff;
        LL l = adj[v][indie[par]].link;
        adj[u][l].first += diff;
        //cout << "AFTER: " << diff << " " << v << " " << indie[par] << " " << adj[v][indie[par]].second << endl;
        return true;
    }
    if (v == s) {
        return false;
    }
    return modify(v, sum, v);
}

void markpath(LL u) {
    pair<LL, LL> &e = pred[u];
    LL v = e.first;
    LL isMod = e.second;

    if (isMod) {
        // Mark isMod as 2
        adj[v][indie[u]].third = 69;
        LL l = adj[v][indie[u]].link;
        adj[u][l].third = 69;
        //cout << "AFTER: " << diff << " " << v << " " << indie[par] << " " << adj[v][indie[par]].second << endl;
    }
    if (v == s) {
        return;
    }
    markpath(v);
}

// An LLeresting issue is where you have multiple shortest
// paths to the same end, using erased edges. You should only select
// one path, and set the rest to infinite. 
// Another hard-to-spot edge case is when you try to assign every 
// edge on the path as 1, and the final unassigned edge as L - path
// to make exactly L. This is problematic because your shortest path
// may avoid the last node because it is very heavy, and you might
// end up using another node next to it. This means we have to run
// dijkstra every time.

/*
    Another super annoying aspect is that I have to prLL only
    one edge of the undirected edges, but the edges can be
    modified on both directions which is really weird... My solution
    is to create an array that holds the index to the adjacency list
    entry. When it outputs it, it will query. In the actual edge 
    itself, it will hold a value poLLing to the 'other' version of
    it, which it will update as well. So both directions are being
    updated at the same time, but the distance only poLLs to
    one of them. Really stupid solution, but not really too much
    I could do since I only realised pretty much 99% of the way
    through my solution.
   */
void solve() {
    cin >> n >> m >> L >> s >> t;

    for (LL i = 0; i < m; ++i) {
        LL u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
            erased.push_back({u,v,w});
        } else {
            LL sz = adj[u].size();
            LL sz2 = adj[v].size();
            adj[u].push_back({w, v, 0, u, -1, sz2});
            adj[v].push_back({w, u, 0, v, -1, sz});
            prLLs.push_back({u, v, sz});
        }
    }

    LL len = dijk();
    if (len < L) {
        cout << "NO\n";
        return;
    }
    for (auto er : erased) {
        LL sz = adj[er.u].size();
        LL sz2 = adj[er.v].size();
        adj[er.u].push_back({1, er.v, 1, er.u, -1, sz2});
        adj[er.v].push_back({1, er.u, 1, er.v, -1, sz});
        prLLs.push_back({er.u , er.v, sz});
    }

    pathtrack();
    if (d[t] == INF) {
        cout << "NO\n";
        return;
    }
    markpath(t);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            //cout << i << " " << adj[i][j].second << " " << adj[i][j].first << " " << adj[i][j].third << endl;
            if (adj[i][j].third == 1) {
                adj[i][j].first = L+1;
            }
        }
    }

    while (1) {
        LL path = pathtrack();
        if (d[t] == INF) {
            cout << "NO\n";
            return;
        }
        if (path == L) {
            cout << "YES\n";
            prLLans();
            return;
        }
        if (!modify(t, path, t)) {
            cout << "NO\n";
            return;
        }
    }
}


