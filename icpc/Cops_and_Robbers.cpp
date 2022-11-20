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

const LL MX = 1e4;
LL n, m, c;
char a[MX][MX];
LL cost[MX];
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

/*
   source INF to Bank
   Any square on the edge connected
   every edge connects to one next to it.
   edge weight is cost of barricading that square
   if connected to DOT, then edge is INF
   max flow is ans
*/

bool check(LL i, LL j) {
    return i >= 0 && j >= 0 && i < m && j < n;
}
bool isEdge(LL i, LL j) {
    return i == 0 || j == 0 || i == m-1 || j == n-1;
}


void solve() {
    cin >> n >> m >> c;
    char gr;
    LL bankid = -1;
    for (LL i = 0; i < m; i++) {
        for (LL j = 0; j < n; j++) {
            cin >> gr;
            a[i][j] = gr;
            if (gr == 'B') {
                bankid = i*n + j;
            }
        }
    }
    for (LL i = 0; i < c; i++) {
        cin >> cost[i];
    }
    //cout << "ENDINPUT\n";
    fill(start, start+MX, -1);
    s = 2*bankid;
    t = 2*(n * m);
    N = t + 1;
    vector<vector<LL>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
    for (LL i = 0; i < m; i++) {
        for (LL j = 0; j < n; j++) {
            LL id = i*n + j;
            LL price = a[i][j] == '.' || a[i][j] == 'B'? INF : cost[a[i][j]-'a']; 
            insert_edge(2*id, 2*id+1, price);

            if (isEdge(i, j)) {
                insert_edge(2*id+1, t, INF);
                continue;
            }

            for (LL k = 0; k < 4; k++) {
                LL x = i+dir[k][0], y = j+dir[k][1];
                LL id2 = x*n + y;
                if (a[x][y] == 'B') continue;
                insert_edge(2*id+1, 2*id2, INF);
            }
        }
    }
    //cout << "beforemf\n";
    LL ret = mf();
    //cout << "aftermf\n";
    cout << (ret == INF ? -1 : ret) << '\n';
}

