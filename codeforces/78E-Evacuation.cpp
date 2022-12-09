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
const LL MX = 1e6;
//const LL MOD = 1e7;

LL n;
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
    //cout << "inserting: " << u << " " << v << " cap: " << c << '\n';
    add_edge(u, v, c); 
    add_edge(v, u, 0);
}

const LL POG = 15;


/*
    Source to all scientists with flow of num scientists
    All pods to sink
    connect scientists to pods if it is reachable before death
    tried floyd warshall, doesn't work because you can have
    your path blocked off by the nuclear thing lol
    had a bug, t = 1 when dfs when should be t = 0
    forgot a check when dfsing to not enter poisoned grid lol.
    weird TLE infinite loop on max case, max time
    memory limit not enough
    time weird
*/

LL timet;
LL sci[POG][POG];
LL grid[61][POG][POG];
LL pod[POG][POG];

LL dp[61][POG][POG][POG][POG];


vector<vector<LL>> dir = {{1, 0},{0,1},{-1,0},{0,-1}};

bool check(LL x, LL y) {
    return x >= 0 && y >= 0 && x < n && y < n && grid[0][x][y] != 1;
}

bool used[POG][POG];
// x,y is the starting spot, ij is current spot
void dfs(LL tim, LL i, LL j, LL x, LL y) {
    //cout <<"dfs... " << i+1 << " " << j+1 << " from: " << x+1 << " " << y+1 << " tim:" << tim << '\n';
    used[i][j] = true;
    dp[tim][x][y][i][j] = 1;
    if (tim >= timet || grid[tim][i][j]) {
        if (grid[tim][i][j]) {
            //cout << "HIT! t: " << tim << " at: " << i+1 << " " << j+1 << endl;
        }
        return;
    }

    for (LL d = 0; d < 4; d++) {
        LL a = i + dir[d][0];
        LL b = j + dir[d][1];
        // In bounds, not visited, not poisoned
        if (check(a, b) && !used[a][b] && !grid[tim][a][b]) {
            dfs(tim+1, a, b, x, y);
        }
    }
}

void solve() {
    fill(start, start+MX, -1);
    cin >> n >> timet;
    s = 250;
    t = s+1;
    N = t+1;
    // Input
    LL reactor = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (isdigit(c)) {
                sci[i][j] = c - '0';
            } else if (c == 'Y') {
                grid[0][i][j] = 1;
            } else if (c == 'Z') {
                grid[0][i][j] = 2; // Single malfunctioning reactor
                reactor = i*n+j;
            }
        }
    }
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (isdigit(c)) {
                pod[i][j] = c - '0';
            }
        }
    }
    // Connecting graph
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            LL id = n*i+j;
            if (sci[i][j]) {
                insert_edge(s, id, sci[i][j]);
            }
            if (pod[i][j]) {
                insert_edge(id+n*n, t, pod[i][j]);
            }
        }
    }
    // propagate nuclear reactor
    for (LL tim = 1; tim <= timet; tim++) {
        for (LL i = 0; i < n; i++) {
            for (LL j = 0; j < n; j++) {
                // If its functioning reactor, leave it
                if (grid[tim-1][i][j] == 1) {
                    grid[tim][i][j] = 1;
                // If its already poisoned, leave it
                } else if (grid[tim-1][i][j] == 2) {
                    grid[tim][i][j] = 2;
                // its unfilled, check if adjacent has poison
                } else {
                    for (LL k = 0; k < 4; k++) {
                        LL x = i + dir[k][0];
                        LL y = j + dir[k][1];
                        if (check(x,y) && grid[tim-1][x][y] == 2) {
                            grid[tim][i][j] = 2;
                        }
                    }
                }
            }
        }
    }
    // check if scientists can reach a pod
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if (sci[i][j]) {
                for (LL k = 0; k < n; k++) {
                    for (LL l = 0; l < n; l++) {
                        used[k][l] = false;
                    }
                }
                dfs(0, i, j, i, j);
            }
        }
    }

    for (LL tim = 1; tim <= timet; tim++) {
        for (LL i = 0; i < n; i++) {
            for (LL j = 0; j < n; j++) {
                for (LL x = 0; x < n; x++) {
                    for (LL y = 0; y < n; y++) {
                        dp[tim][i][j][x][y] = dp[tim-1][i][j][x][y] || dp[tim][i][j][x][y] ? 1 : 0;
                    }
                }
            }
        }
    }

    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            for (LL x = 0; x < n; x++) {
                for (LL y = 0; y < n; y++) {
                    if (dp[timet][i][j][x][y] && sci[i][j] && pod[x][y]) {
                        insert_edge(i*n+j, x*n+y+n*n, INF);
                    }
                }
            }
        }
    }
    cout << mf() << '\n';
}


