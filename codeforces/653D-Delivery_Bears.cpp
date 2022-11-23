#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();
LL casenum;

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
        solve();
}

#define INF numeric_limits<LL>::max() / 2

const LL MX = 1e4;
LL N, s, t;
LL n, m, x;

vector<pair<LL, LL>> adj[MX];

LL lvl[MX];
LL nextchld[MX];
LL start[MX];
LL succ[MX], cap[MX], to[MX];
LL edge_counter = 0;

bool bfs() {
    for (LL i = 0; i < N; i++) lvl[i] = -1;
    queue<LL> q;
    q.push(s); lvl[s] = 0;
    while (!q.empty()) {
        LL u = q.front(); q.pop();
        nextchld[u] = start[u]; 
        for (LL e = start[u]; ~e; e = succ[e]) {
            if (cap[e] > 0) {
                LL nxt = to[e];
                if (lvl[nxt] != -1) continue;
                lvl[nxt] = lvl[u] + 1;
                q.push(nxt);
            }
        }
    }
    return lvl[t] != -1;
}

LL aug(LL u, LL cflow) {
    if (u == t) return cflow; 
    for (LL &i = nextchld[u]; i >= 0; i = succ[i]) {
        if (cap[i] > 0) {
            LL nxt = to[i];
            if (lvl[nxt] != lvl[u] + 1) continue;
            LL rf = aug(nxt, min(cflow, cap[i]));
            if (rf > 0) {
                cap[i] -= rf;
                cap[i^1] += rf;
                return rf;
            }
        }   
    }
    lvl[u]=-1;
    return 0;
}

LL mf() {
    LL tot = 0;
    while (bfs())
        for (LL x = aug(s,INF); x; x = aug(s,INF)) tot+=x;
    return tot;
}

void add_edge(LL u, LL v, LL c) {
    cap[edge_counter] = c, to[edge_counter] = v;
    succ[edge_counter] = start[u];
    start[u] = edge_counter;
    ++edge_counter;
}

void insert_edge(LL u, LL v, LL c) {
    add_edge(u, v, c); 
    add_edge(v, u, 0);
}


void solve() {
    cin >> n >> m >> x;
    for (LL i = 0; i < m; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    
    s = 0;
    t = n-1;
    N = t+1;
    double ret = -1;
    double lo = 0;
    double hi = 1e7;
    for (LL it = 0; it < 70; it++) {
        double mid = (lo + hi) / 2;
        //cout << "mid: " << mid << endl;
        for (LL i = 0; i < n*2; i++) {
            lvl[i] = nextchld[i] = succ[i] = cap[i] = to[i];
            start[i] = -1;
        }
        edge_counter = 0;

        for (LL i = 0; i < n; i++) {
            for (pair<LL, LL> j : adj[i]) {
                LL v = j.first, w = j.second;
                if ((double)w >= mid) {
                    //cout << "edge inserted: " << i+1 << " " << v+1 << " " << floor((double)w / mid) << endl;
                    insert_edge(i, v, floor((double)w / mid));
                }
            }
        }
        LL paths = mf();
        //cout << "PATHSPATHSPATHS: " << paths << endl;
        if (paths < x) {
            hi = mid;
        } else {
            lo = mid;
            ret = max(ret, (double)x * mid);
        }
    }
    cout << fixed << setprecision(10) << ret << '\n';
}
