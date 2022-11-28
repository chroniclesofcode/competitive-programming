#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();
int casenum;

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
        solve();
}

#define INF numeric_limits<int>::max() / 2

const int MX = 1e5;
int N, s, t;
int n, m, ab, ba;

int lvl[MX];
int nextchld[MX];
int start[MX];
int succ[MX], cap[MX], to[MX];
int edge_counter = 0;

bool seen1[MX], seen2[MX];

bool bfs() {
    for (int i = 0; i < N; i++) lvl[i] = -1;
    queue<int> q;
    q.push(s); lvl[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        nextchld[u] = start[u]; 
        for (int e = start[u]; ~e; e = succ[e]) {
            if (cap[e] > 0) {
                int nxt = to[e];
                if (lvl[nxt] != -1) continue;
                lvl[nxt] = lvl[u] + 1;
                q.push(nxt);
            }
        }
    }
    return lvl[t] != -1;
}

int aug(int u, int cflow) {
    if (u == t) return cflow; 
    for (int &i = nextchld[u]; i >= 0; i = succ[i]) {
        if (cap[i] > 0) {
            int nxt = to[i];
            if (lvl[nxt] != lvl[u] + 1) continue;
            int rf = aug(nxt, min(cflow, cap[i]));
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

int mf() {
    int tot = 0;
    while (bfs())
        for (int x = aug(s,INF); x; x = aug(s,INF)) tot+=x;
    return tot;
}

void add_edge(int u, int v, int c) {
    cap[edge_counter] = c, to[edge_counter] = v;
    succ[edge_counter] = start[u];
    start[u] = edge_counter;
    ++edge_counter;
}

void insert_edge(int u, int v, int c) {
    add_edge(u, v, c); 
    add_edge(v, u, 0);
}

/*
    We DFS the residual graph from s and from t.
    Basically, we travel until we hit the actual min cut.
    Note that every single node until that specific min cut
    will ALWAYS have residual flow aka capacity left, otherwise
    that would be the min cut. 
    Of course, if the smallest path has similar bottleneck
    values along it, we may encounter some nodes with no
    capacity. However, if this happens, there is always some
    other path to take. If not, this is a min cut. 
    And note that we can never reach PAST this min cut, all
    the reachable nodes from S will be in your partition A
    and nothing from B will be there. This is because you cannot
    go past all of your min cut edges -> they all have 0 capacity.
    That's pretty much it.
    Just find the two partitions, and if they don't make up
    the entire graph, then it's not unique.

    note when travelling from t, we are trying to do the same 
    operation but moving backwards up the graph. So we traverse
    the residuals, but we check the actual capacity value of
    the actual flow... 
*/

int ans1 = 0, ans2 = 0;

void check_reach1(int u) {
    if (seen1[u]) return;
    //cout << "U1: " << u+1 << endl;
    seen1[u] = true;
    ans1++;
    for (int e = start[u]; ~e; e = succ[e]) {
        //cout << "from: " << u+1 << " to: " << to[e]+1 << " cap: " << cap[e] << endl;
        if (cap[e] > 0) check_reach1(to[e]);
    }
}

void check_reach2(int u) {
    if (seen2[u]) return;
    //cout << "U2: " << u+1 << endl;
    seen2[u] = true;
    ans2++;
    for (int e = start[u]; ~e; e = succ[e]) {
    //cout << "from: " << u+1 << " to: " << to[e]+1 << " cap: " << cap[e^1] <<  " " << (e^1) << endl;
        if (cap[e^1] > 0) check_reach2(to[e]);
    }
}

void solve() {
    ifstream fin("attack.in");
    ofstream fout("attack.out");
    fin >> n >> m >> ab >> ba;
    ab--;
    ba--;
    fill(start, start+MX, -1);
    N = n+1;
    s = ab;
    t = ba;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        a--; b--;
        insert_edge(a, b, c);
        insert_edge(b, a, c);
    }
    mf();
    check_reach1(ab);
    check_reach2(ba);
    //cout << "ANS: " << ans1 << " " << ans2 << endl;
    if (ans1 + ans2 == n) {
        fout << "UNIQUE\n";
    } else {
        fout << "AMBIGUOUS\n";
    }

}

/*

   8 8
1
8
1 2 10
2 4 2
4 5 1
2 3 3
3 5 3
5 6 3
6 7 9
7 8 10
*/
