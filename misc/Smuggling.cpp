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
const LL MX = 1e6;

LL N, s, t;

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

pair<LL, LL> c[MX];

void solve() {
    LL n, m;
    cin >> n >> m;
    N = n;
    s = 0;
    t = n-1;
    fill(start, start+N, -1);
    for (LL i = 0; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        c[i] = { x, y };
    }
    for (LL i = 0; i < n-1; i++) {
        for (LL j = 1; j < n; j++) {
            if (i == j) continue;
            double diff = sqrt(pow((double)c[i].first - (double)c[j].first, 2) + pow((double)c[i].second - (double)c[j].second, 2));
            if (diff <= 1.0) {
                insert_edge(i, j, 1);
            }
        }
    }
    if (mf()/2 >= m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}








