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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;
LL N, s, t, m;

LL lvl[MX];
LL nextchld[MX];
LL start[MX];
LL succ[MX], cap[MX], to[MX], vis[MX];
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

void _add_edge(LL u, LL v, LL c) {
    cap[edge_counter] = c, to[edge_counter] = v;
    succ[edge_counter] = start[u];
    start[u] = edge_counter;
    ++edge_counter;
}

void add_edge(LL u, LL v, LL c) {
    _add_edge(u, v, c); 
    _add_edge(v, u, 0);
}

vector<LL> ans;

void dfs(LL u, LL edg) {
    vis[edg] = true;
    ans.push_back(u);
    if (u == t) {
        return;
    }
    for (LL e = start[u]; ~e; e = succ[e]) {
        if (cap[e] == 0 && !vis[e] && e%2 == 0) {
            dfs(to[e], e);
            return;
        }
    }
}


void solve() {
    fill(start, start+MX, -1);

    cin >> N >> m;
    LL a, b;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        add_edge(a, b, 1);
    }
    s = 0;
    t = N-1;
    LL res = mf();
    cout << res << endl;

    for (LL i = 0; i < res; i++) {
        ans.clear();
        dfs(0, MX-1);
        cout << ans.size() << '\n';
        for (auto &val : ans) {
            cout << val+1 << ' ';
        }
        cout << '\n';
    }

}





