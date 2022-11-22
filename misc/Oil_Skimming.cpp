#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();
LL casenum;

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    for (casenum = 1; casenum <= t; casenum++)
        solve();
}

#define INF numeric_limits<LL>::max() / 2

const LL MX = 1e4;
LL N, s, t;
LL n;

char a[MX][MX];

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

vector<vector<LL>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

bool check(LL i, LL j) {
    return i >= 0 && j >= 0 && i < n && j < n && a[i][j] == '#';
}

void solve() {
    cin >> n;
    char ctmp;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            cin >> ctmp;
            a[i][j] = ctmp;
        }
    }
    fill(start, start+MX, -1);
    for (LL i = 0; i < n*n+10; i++) {
        lvl[i] = 0;
        nextchld[i] = 0;
        succ[i] = 0;
        cap[i] = 0;
        to[i] = 0;
        edge_counter = 0;
    }

    s = 2*(n*n);
    t = s+1;
    N = t+1;
    
    for (LL i = 0; i < n; i++) {
        LL start = i % 2 == 1 ? 0 : 1;
        for (LL j = start; j < n; j+=2) {
            if (check(i, j)) {
                LL id = i*n+j;
                insert_edge(2*id, 2*id+1, 1);
                insert_edge(2*id+1, t, 1);
            }
        }
    }

    for (LL i = 0; i < n; i++) {
        LL start = i % 2 == 1 ? 1 : 0;
        for (LL j = start; j < n; j+=2) {
            LL id = i*n+j;
            if (check(i, j)) {
                //cout << i << j << "runs\n";
                insert_edge(s, 2*id, 1);
                insert_edge(2*id, 2*id+1, 1);
            } else {
                continue;
            }
            for (LL k = 0; k < 4; k++) {
                LL x = i + dirs[k][0];
                LL y = j + dirs[k][1];
                LL id2 = x*n+y;
                if (check(x, y)) {
                    //cout << i << j << "runsajhdjhasda\n";
                    insert_edge(2*id+1, 2*id2, 1);
                }

            }
        }
    }
    cout << "Case " << casenum << ": " << mf() << '\n';
}

