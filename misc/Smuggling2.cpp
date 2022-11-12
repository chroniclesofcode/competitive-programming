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
const LL MX = 1e5;

LL n, m;
LL N, s, t, real, MD;

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
    //cout << "added: " << u << " and " << v << " with " << c << endl;
    add_edge(u, v, c); 
    add_edge(v, u, 0);
}

pair<LL, LL> c[MX];

double euclid(double x1, double x2, double y1, double y2) {
    return (x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2);
}


bool poggers(double mdist) {
    //cout << "EMDEE: " << MD << " " << mdist * mdist << endl;
    if (MD < mdist * mdist) {
        //cout << "GONE LIKE DA WIND\n";
        return true;
    }
    for (LL i = 0; i < MX; i++) {
        start[i] = -1;
        lvl[i] = nextchld[i] = succ[i] = cap[i] = to[i] = 0;
    }
    edge_counter = 0;

    s = 2*n;
    //fake = 2*n+1; // sink
    t = 2*n+1;
    N = 2*n+2;
    insert_edge(s, 0, INF);
    insert_edge(0, 1, INF);
    for (LL i = 1; i < n-1; i++) {
        insert_edge(2*i, 2*i+1, 1);
    }
    insert_edge(2*(n-1), 2*(n-1)+1, INF);
    for (LL i = 0; i < n-1; i++) {
        for (LL j = 1; j < n; j++) {
            if (euclid(c[i].first, c[i].second, c[j].first, c[j].second) <= mdist*mdist) {
                insert_edge(2*i+1, 2*j, INF);
            }
        }
    }

    insert_edge(2*(n-1)+1, t, 2*m);
    LL ret = mf();
    //cout << "MFMFMFMFMFMFMFMFMFMMFMFMFMFMF: " <<  ret << " " << 2*m << " " << s << " " << t <<  endl;
    return ret == 2*m;
}

void solve() {
    cin >> n >> m;
    s = 0;
    t = n-1;
    //fill(start, start+N, -1);
    for (LL i = 0; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        c[i] = { x, y };
    }
    MD = euclid(c[0].first, c[0].second, c[n-1].first, c[n-1].second);
    //cout << "EUCLID: " << euclid(c[5].first, c[5].second, c[4].first, c[4].second) << endl;
    //cout << poggers(13) << endl;
    double lo = 0, hi = 1e10;
    for (LL it = 0; it < 70; it++) {
        double mid = (lo + hi) / 2;
        //cout << "test " << lo << " " << mid << " " << hi << endl;
        if (poggers(mid)) hi = mid;
        else lo = mid;
    }
    cout << (long long)ceil(lo) << '\n';

    /*

       5 3 1 1 3 4 3 2 4 5 5 5
       6 2 1 5 6 7 11 7 11 3 6 3 16 5

    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if (i == j) continue;
            if (j == 0) continue;
            if (i == n-1) continue;
            double diff = sqrt(pow((double)c[i].first - (double)c[j].first, 2) + pow((double)c[i].second - (double)c[j].second, 2));
            if (diff <= 1.0) {
                insert_edge(i, j, 1);
            }
        }
    }
    if (mf() >= m*2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    */
}








